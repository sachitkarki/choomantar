// Carrier.h: interface for the Carrier class.
//
//////////////////////////////////////////////////////////////////////
#ifndef __CARRIER_H_
#define __CARRIER_H_

#include "ICarrier.h"
#include "..\common\stegokey.h"

class Carrier  :public ICarrier
{
public:
	Carrier();

	/*
	 *This function is used to set the key both before Hide and UnHide is called.
	 *Parameter
		char *key - This should contain the key(Password) which would be used to Hide or Unhide the data
	 */
	virtual void setKey(char *key) ;

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

	
		This function takes the same parameters as hide function above.
		This provide an incomplete implementation of the function .
	*/
	 	virtual void hide(char *carrierFile,char *destFile,char *dataFile) ;

	/*
	 *This function is called to unHide the data from a Carrier file
	 This function should be called after seting the key with setKey function
	 char *carrierFile - This variable should contain the Carrier file name in which data is hidden and we want to Unhide.
							It should be with the complete path of the file e.g:- c:\documents\withDataCarrier.bmp
		char *dataFile - This variable should contain the destination file name which will be created and the data hidden in the carrier will be wriiten into this file.
							It should be with the complete path of the file e.g:- c:\documents\outputWithData.txt

  		This function takes the same parameters as unHide function above.
		This provide an incomplete implementation of the function .
	 */
	virtual void unHide(char *carrierFile,char *dataFile) ;

	
	virtual ~Carrier();
protected :

	/*
	This function takes the same parameters as hide function and used in the implementation of the hide function provided in this class(Incomplete Implementation
	The base class deriving from Carrier should implement this .
	A defaul implementation is provide to always return true
	The logic to check whether the current carrier can hide the current data should be present here.
	*/
	virtual bool canHide(char *carrierFile,char *destFile,char *dataFile);

	/*
	This function takes the same parameters as unHide function and used in the implementation of the hide function provided in this class(Incomplete Implementation
	The base class deriving from Carrier should implement this .
	A defaul implementation is provide to always return true
	The logic to check whether the current carrier can UnHide the current data should be present here.
	*/
	virtual bool canUnhide(char *carrierFile,char *dataFile);

	/*
	This function takes the same parameters as hide function and used in the implementation of the hide function provided in this class(Incomplete Implementation
	The base class deriving from Carrier should implement this .
	This function would contain the basic  logic for Hiding in a particular Carrier
	*/
	virtual void hideInCarrier(char *carrierFile,char *destFile,char *dataFile) = 0;

	/*
	This function takes the same parameters as unHide function and used in the implementation of the hide function provided in this class(Incomplete Implementation
	The base class deriving from Carrier should implement this .
	This function would contain the basic  logic for UnHiding in a particular Carrier
	*/
	virtual void unHideInCarrierFile(char *carrierFile,char *dataFile) = 0;

	stegokey *m_pStegoKey;
};

#endif 