
#include "CommonDefs.h"

#include "FileManager.h"

class data
{
protected:
	FileManager datafile ;
public:
	bool openforread(char *filename);
	//int getdata(int from ,int howmany,BYTE *buff);
	unsigned int getdata(int from ,int howmany,BYTE *buff,int *howmanyread);
	bool openforwrite(char *filename);
	unsigned int putdata(int from,int howmany,BYTE *buff);
	unsigned int getdataforwrite(int from ,int howmany,BYTE *buff,int *howmanyread);
	unsigned int length();
	void close();
};