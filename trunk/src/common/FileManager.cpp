// FileManager.cpp: implementation of the FileManager class.
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "FileManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FileManager::FileManager()
{
m_pFile =NULL;
}

FileManager::~FileManager()
{
	if(m_pFile){
			Close();
	}
}
bool FileManager::Open(char *fileName, fileMode mode)
{
	
	switch(mode){

	case ReadMode:
		{
		m_pFile = fopen(fileName , "rb");
		break;
		}
	case ReadWriteMode:
		{
		m_pFile = fopen(fileName , "rb+");
		break;			  
		}

	case ReadWriteCreateMode:
		{
		m_pFile = fopen(fileName , "wb+");
		break;
		}

	}


	if(m_pFile == NULL){

		return false;
		
	}else{

		return true;
	}
}

unsigned int FileManager::Read(void *buf, unsigned int noOfBytes)
{
	 unsigned int noOfBytesRead =0; 
	
	 if(NULL != m_pFile){

		noOfBytesRead = fread(buf,1,noOfBytes,m_pFile);
		if(ferror(m_pFile))
			printf("File Error");
	 
	 }
	 return noOfBytesRead;
}



int FileManager::Seek(unsigned int noOfBytes, seekFrom fromWhere)
{
	int returnVal=0;

	switch(fromWhere){
	

		case BeginSeek:
			{
				returnVal =  fseek(m_pFile,noOfBytes,SEEK_SET);
				break;
			 }
		case CurrentSeek:
			{
				returnVal =  fseek(m_pFile,noOfBytes,SEEK_CUR);
				break;
			 }

		case EndSeek:
			{
				returnVal =  fseek(m_pFile,noOfBytes,SEEK_END);
				break;
			 }

	
	}
	return returnVal;

}

unsigned int FileManager::Write(void *buf, unsigned int noOfBytes)
{
	int noOfBytesWritten=0;

	noOfBytesWritten = fwrite(buf,1,noOfBytes,m_pFile);

	return noOfBytesWritten;
}




void FileManager::Close()
{
	fclose(m_pFile);
	m_pFile = NULL;

}

unsigned long  FileManager::GetLength()
{

	long currentPos = ftell(m_pFile);

	Seek(0,EndSeek);

	long length = ftell(m_pFile);
	
	Seek(currentPos,BeginSeek);



return length;
}

void FileManager::Flush()
{
	fflush(m_pFile);
}

unsigned int FileManager::SeekToBegin()
{

	return Seek(0,BeginSeek);
}

void FileManager::Remove(char *fileName)
{
	remove(fileName);
}

unsigned FileManager::getPosition()
{
	return ftell(m_pFile);
}
