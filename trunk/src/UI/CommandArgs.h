#ifndef __COMMANDARGS_H__
#define __COMMANDARGS_H__

#include "IUserInterface.h"


class CommandArgs:public IUserInterface
{
public:
	CommandArgs(int argc,char*argv[]);

protected:

	virtual int getOptions();
	virtual void getDataForHide(char* inputFileName ,  char* outputFileName , char* dataFileName ,  char * password);
	virtual void getDataForUnHide(char* inputFileName ,  char* outputDataFileName ,  char * password);
 
private:
	int noOfArguments;
	char * option;
	char * inputCarrier;
	char * outputCarrier;
	char * pass;
	char * dataFile;

};

#endif