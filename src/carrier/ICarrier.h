// ICarrier.h: interface for the ICarrier class.
//
//////////////////////////////////////////////////////////////////////


#ifndef __ICARRIER_H_
#define __ICARRIER_H_

/*
This class acts as an interface for all the Carrier  classes .
All carrier classes should implemet this interface.

 */
class ICarrier  
{
public:
	ICarrier();
	/*
	 *This function is used to set the key both before Hide and UnHide is called.
	 *Parameter
		char *key - This should contain the key(Password) which would be used to Hide or Unhide the data
	 */
	virtual void setKey(char *key) = 0;

	/*
	 *This function is called to hide data in the Carrier File.
	 This function should be called after seting the key with setKey function
	 * This function will contain the logic to hide the file depending on the type of carrier file .
	 Parameters :-
		char *carrierFile - This variable should contain the Carrier file name in which we want to hide the data.
							It should be with the complete path of the file e.g:- c:\documents\inputCarrier.bmp
		char *destFile - This variable should contain the destination file name which will be created with the data hidden in it.
							It should be with the complete path of the file e.g:- c:\documents\outputWithData.bmp
		char *dataFile - This should the data file which is to be hiided inside the carrier..
						It should be with the complete path of the file e.g:- c:\documents\data.txt
	 */
	virtual void hide(char *carrierFile,char *destFile,char *dataFile) = 0;

	/*
	 *This function is called to unHide the data from a Carrier file
	 This function should be called after seting the key with setKey function
	 char *carrierFile - This variable should contain the Carrier file name in which data is hidden and we want to Unhide.
							It should be with the complete path of the file e.g:- c:\documents\withDataCarrier.bmp
		char *dataFile - This variable should contain the destination file name which will be created and the data hidden in the carrier will be wriiten into this file.
							It should be with the complete path of the file e.g:- c:\documents\outputWithData.txt
	 */
	virtual void unHide(char *carrierFile,char *dataFile) = 0;


	virtual ~ICarrier();

};

#endif 
