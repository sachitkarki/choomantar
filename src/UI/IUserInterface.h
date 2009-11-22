#ifndef __IUSERINTERFACE_H_
#define __IUSERINTERFACE_H_


	enum Options{
	 EXIT =0,
	 HIDE,
	 UNHIDE
	};


class IUserInterface{

public:



	virtual int getOptions() = 0;
	virtual bool getDataForHide(char* inputFileName ,  char* outputFileName , char* dataFileName ,  char * password) = 0;
	virtual bool getDataForUnHide(char* inputFileName ,  char* outputDataFileName ,  char * password) = 0;
	
	
};


#endif