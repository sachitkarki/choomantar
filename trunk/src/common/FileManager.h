// FileManager.h: interface for the FileManager class.
//
//////////////////////////////////////////////////////////////////////


#ifndef __FILEMANAGER_H_
#define __FILEMANAGER_H_

#include<stdio.h>
	
enum fileMode{

	ReadMode =0,
	ReadWriteMode,
	ReadWriteCreateMode

};


enum seekFrom{

	BeginSeek =0,
	CurrentSeek,
	EndSeek

};



class FileManager  
{

	
public:
	unsigned getPosition();
	static void Remove(char* fileName);
	unsigned int SeekToBegin();

	


	
	
	void Flush();
	unsigned long GetLength();
	void Close();
	unsigned int Write(void * buf , unsigned int noOfBytes);
	int Seek(unsigned int noOfBytes,seekFrom fromWhere);
	unsigned int Read(void* buf,unsigned int noOfBytes);
	bool Open(char* filename, fileMode mode);
	FileManager();
	virtual ~FileManager();




private:
	FILE* m_pFile;


};


#endif