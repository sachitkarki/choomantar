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
	virtual void getDataForHide(char* inputFileName ,  char* outputFileName , char* dataFileName ,  char * password) = 0;
	virtual void getDataForUnHide(char* inputFileName ,  char* outputDataFileName ,  char * password) = 0;
	
};


#endif