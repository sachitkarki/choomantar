#ifndef __COMMANDLINEUI_H__
#define __COMMANDLINEUI_H__

#include "IUserInterface.h"


class CommandLineUI:public IUserInterface
{

protected:

	virtual int getOptions();
	virtual void getDataForHide(char* inputFileName ,  char* outputFileName , char* dataFileName ,  char * password);
	virtual void getDataForUnHide(char* inputFileName ,  char* outputDataFileName ,  char * password);



};

#endif