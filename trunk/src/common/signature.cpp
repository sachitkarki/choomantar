#include <stdio.h>
#include<iostream>
#include "Signature.h"
#include "FileManager.h"
#include "string.h"


using namespace std;

void removesignature(char *infilename)
{

	FileManager infile ,outfile;
	char *outfilename = "temp.jsa";
	char sig[3];
	BYTE buff[512];
	if(!infile.Open(infilename,ReadMode)){ throw new Exception("Cannot write output data file"); }
	
	if(!outfile.Open(outfilename,ReadWriteCreateMode)){ infile.Close();throw new Exception("Cannot write output data file"); }
	
	infile.Read(sig,3);
	if(memcmp(sig,"JSA",3)!=0)
	{
		infile.Close();
		outfile.Close();
		FileManager::Remove(outfilename);
		throw new Exception("Incorrect Password"); 
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
		Replicate(outfilename,infilename);
		FileManager::Remove(outfilename);
}
	




void Replicate(char *infilename,char *outfilename)
{

	FileManager infile ,outfile;
	BYTE buff[512];
	if(!infile.Open(infilename,ReadMode)){ throw new Exception("Cannot open Carrier file"); }
		
	if(!outfile.Open(outfilename,ReadWriteCreateMode)){ infile.Close();throw new Exception("Cannot Create output file."); }
		
	int lenght=infile.GetLength();
	int noofbytesread;

	int curPos = 0 , lastPos =0;
	while(lenght>512)
	{
		noofbytesread=infile.Read(buff,512);
		outfile.Write(buff,noofbytesread);

		//Added for debugging
		//curPos = infile.getPosition();
		//if( (curPos - 512 ) != lastPos)
		//{
		//	cout<<"\n"<<lastPos<<"\t"<<curPos<<"\t"<<curPos-lastPos<<"\t"<<noofbytesread;
		//	int a ;
		//	cin>>a;
		//}
		//lastPos = curPos;
		
		lenght-=512;
	}
	
		noofbytesread=infile.Read(buff,lenght);
		outfile.Write(buff,noofbytesread);

		infile.Close();
		outfile.Close();
}
	
