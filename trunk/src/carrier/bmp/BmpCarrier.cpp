// BmpCarrier.cpp: implementation of the BmpCarrier class.
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "BmpCarrier.h"
#include "..\..\common\signature.h"
#include "..\..\common\Random.h"
#include "..\..\common\Exception.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


BmpCarrier::BmpCarrier():Carrier()
{

}

BmpCarrier::~BmpCarrier()
{
	
}



bool BmpCarrier::isSignatureBmp()
{	

	char bmpSignature[2];

	carrier.SeekToBegin();

	if ( carrier.Read(bmpSignature,2) != 2) { throw new Exception("Cannot read the carrier BMP file."); }
	
	if(bmpSignature[0]!='B' || bmpSignature[1]!='M') { throw new Exception("The carrier BMP file is not a valid BMP file."); }

return true;
}


bool BmpCarrier::canHide(char *carrierFile,char *destFile,char *dataFile)
{

	bool breturnValue = false;

	Replicate(carrierFile,destFile);
	//---------------------------------------------

	//check if carrier cannot be opened
	if(!carrier.Open(destFile, ReadWriteMode)){ throw new Exception("Cannot open the Carrier BMP file."); }
	
	//check if data file cannot be opened
	if(!inputData.openforread(dataFile)) { throw new Exception("Cannot open the input data file."); }

	isSignatureBmp(); //check if valid signature

	carrier.Seek(10,BeginSeek);
	carrier.Read(&imageOffset,4);

	imageSize = carrier.GetLength() - imageOffset - 32;   //32 left for lenght
	
	noOfRegions = imageSize / REGION_SIZE;

	if( imageSize % REGION_SIZE != 0)
		noOfRegions++;

	if(inputData.length() > imageSize / CARRIER_TO_DATA_RATIO) { throw new Exception("The data file is too big to hide in this carrier"); }
	
	//--------------------------------------------
	breturnValue = true;
	return breturnValue;

}

bool BmpCarrier::canUnhide(char *carrierFile,char *dataFile)
{

	bool breturnValue = false;
	//------------------------------------------------
	BYTE buff[32];

	//check if carrier cannot be opened
	if(!carrier.Open(carrierFile,ReadWriteMode)){ throw new Exception("Cannot open the Carrier BMP file."); }
	
	//check if data file cannot be opened
	if(!inputData.openforwrite(dataFile)) { throw new Exception("Cannot create the output data file."); }
		
	isSignatureBmp(); //check if valid signature

	carrier.Seek(10,BeginSeek);

	carrier.Read(&imageOffset,4);
	
	imageSize = carrier.GetLength() - imageOffset - 32; //size in first 32 bytes
	
	noOfRegions = imageSize / REGION_SIZE;

	if( imageSize % REGION_SIZE != 0)
		noOfRegions++;

	carrier.Seek(imageOffset,BeginSeek);
	carrier.Read(buff,32);
	
	dataLength = 0;

	int t1,t;
	for(int i = 0 ; i < 32 ; i++)
	{
		t= 1 << i;

		t1 = buff[i] & 1;

		if(t1 != 0)
			dataLength = t | dataLength;
	}

	imageOffset += 32;

	//-------------------------------------------------
	breturnValue = true;
	return breturnValue;

}

	
void BmpCarrier::hideInCarrier(char *carrierFile,char *destFile,char *dataFile)
{


	BYTE buff[REGION_SIZE];
	RandomGenerator randomGenerator;  
	unsigned int i , noOfBytesRead,length;
	
	//Skip header and go to the image data . imageOffset gets initialised in canHide/UnHide

	carrier.Seek(imageOffset,BeginSeek);

	//put data length in first 32 bytes of image data
	
	carrier.Read(buff,32);
	
	length=inputData.length();

	for(i=0;i<32;i++)
	{
		int k = 1 << i;

		k = k & length;
		
		if(k==0)
			buff[i] = buff[i] & 0xfe;
		else
			buff[i] = buff[i] | 1;

	}
	
	//write data with datalength back in the image to hide

	carrier.Seek(imageOffset,BeginSeek);
	carrier.Write(buff,32);

	imageOffset += 32;

	for(i=0 ; i < noOfRegions ; i++)
	{
		unsigned int z = i * REGION_SIZE + imageOffset;
	
		carrier.Seek(i * REGION_SIZE + imageOffset, BeginSeek);
		noOfBytesRead = carrier.Read(buff, REGION_SIZE);
		randomGenerator.setRangeAndSeed(m_pStegoKey->converttonum(), noOfBytesRead);
		
		unsigned int t=0,bitNo=i,byteNo;

		while(t!=-1)
		{
			t = inputData.getBitNo(bitNo);
			byteNo = randomGenerator.nextRandom();

			 
			if(t == -1)
				break;    //if the bit was not read properly break
			else if (t == 0)
				buff[byteNo] &= 0xfe;
			else
				buff[byteNo] |= 1;
		
			bitNo += noOfRegions;
		
		}
	
		carrier.Seek(i * REGION_SIZE + imageOffset, BeginSeek);
		carrier.Write(buff, noOfBytesRead);

	}
	carrier.Flush();

}

void BmpCarrier::unHideInCarrierFile(char *carrierFile,char *dataFile)
{

	BYTE buff[REGION_SIZE];
	RandomGenerator randomGenerator; 
	unsigned int i, noOfBytesRead, totalDataBits;
	
	totalDataBits= 8 * dataLength; //Data length set in canUnhide
	
	//read every region and put the data in it randomly with the help of random generator

	for( i = 0 ; i < noOfRegions ; i++)
	{
		unsigned int z = i * REGION_SIZE + imageOffset;
		carrier.Seek(i * REGION_SIZE + imageOffset, BeginSeek);
		noOfBytesRead=carrier.Read(buff, REGION_SIZE);


		randomGenerator.setRangeAndSeed(m_pStegoKey->converttonum(), noOfBytesRead);
		unsigned int t = 0,bitNo=i,byteNo=0;

		while(bitNo < totalDataBits)
		{
			
			byteNo=randomGenerator.nextRandom();

			t = buff[byteNo] & 1;
			if(t == 0)
				inputData.putBitNo(bitNo, 0);
			else
				inputData.putBitNo(bitNo, 1);
			bitNo += noOfRegions;
	
		}
	}

	inputData.flushBuff();

}
