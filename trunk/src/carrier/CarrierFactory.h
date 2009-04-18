// CarrierFactory.h: interface for the CarrierFactory class.
//
//////////////////////////////////////////////////////////////////////
#ifndef __CARRIER_FACTORY_H_
#define __CARRIER_FACTORY_H_


/*
This class is responsile to create the appropriate carrier objects.
(based on the extension of the file).
This class contains only a static function .

 */

#include "ICarrier.h"
class CarrierFactory  
{
private:
	CarrierFactory();
	virtual ~CarrierFactory();
public:

	/*
	This funtion creates an appropriate object on the Carrier base class , depending on the extension passed.
	Parameters :-
		char *ext - This parameter the extion of the carrier file should be passed e.g. bmp , jpg etc.
	*/
	static ICarrier *GetCarrier(const char *ext);

};

#endif 