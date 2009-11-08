class IUserInterface{

public:

	enum Options{
	 HIDE,
	 UNHIDE,
	 EXIT
	};

	virtual Options getOptions() = 0;
	virtual void getDataForHide(char* inputFileName ,  char* outputFileName , char* dataFileName ,  char * password) = 0;
	virtual void getDataForUnHide(char* inputFileName ,  char* outputDataFileName ,  char * password) = 0;

};