#include <stdio.h>
#include "Signature.h"
#include "FileManager.h"
#include "string.h"
#include<iostream.h>

void removesignature(char *infilename,char *outfilename)
{

	FileManager infile ,outfile;
	char sig[3];
	BYTE buff[512];
	if(!infile.Open(infilename,ReadMode))
		throw IO_ERROR_HANDLING_FILE;
	if(!outfile.Open(outfilename,ReadWriteCreateMode))
		throw IO_ERROR_HANDLING_FILE;

	infile.Read(sig,3);
	if(memcmp(sig,"JSA",3)!=0)
	{
		infile.Close();
		outfile.Close();
		FileManager::Remove(outfilename);

	throw VALIDATION_FAILED; 

	}

	int lenght=infile.GetLength()-3;
	int noofbytesread;

	while(lenght>512)
	{
		noofbytesread=infile.Read(buff,512);
		outfile.Write(buff,noofbytesread);
		lenght-=512;
	}
	
		noofbytesread=infile.Read(buff,lenght);
		outfile.Write(buff,noofbytesread);

		infile.Close();
		outfile.Close();
		FileManager::Remove(infilename);
}
	




void Replicate(char *infilename,char *outfilename)
{

	FileManager infile ,outfile;
	BYTE buff[512];
	if(!infile.Open(infilename,ReadMode))
		throw IO_ERROR_HANDLING_FILE;
	if(!outfile.Open(outfilename,ReadWriteCreateMode))
		throw IO_ERROR_HANDLING_FILE;


	int lenght=infile.GetLength();
	int noofbytesread;

	int curPos = 0 , lastPos =0;
	while(lenght>512)
	{
		noofbytesread=infile.Read(buff,512);
		outfile.Write(buff,noofbytesread);

		curPos = infile.getPosition();

		if( (curPos - 512 ) != lastPos)
		{
			cout<<"\n"<<lastPos<<"\t"<<curPos<<"\t"<<curPos-lastPos<<"\t"<<noofbytesread;
			int a ;
			cin>>a;
		}
		lastPos = curPos;
	

		lenght-=512;
	}
	
		noofbytesread=infile.Read(buff,lenght);
		outfile.Write(buff,noofbytesread);

		infile.Close();
		outfile.Close();
}
	

