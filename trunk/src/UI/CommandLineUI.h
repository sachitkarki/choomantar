#ifndef __COMMANDLINEUI_H__
#define __COMMANDLINEUI_H__

#include "IUserInterface.h"


class CommandLineUI:public IUserInterface
{

protected:

	virtual int getOptions();
	virtual bool getDataForHide(char* inputFileName ,  char* outputFileName , char* dataFileName ,  char * password);
	virtual bool getDataForUnHide(char* inputFileName ,  char* outputDataFileName ,  char * password);



};

#endif