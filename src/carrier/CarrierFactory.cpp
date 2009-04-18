// CarrierFactory.cpp: implementation of the CarrierFactory class.
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "CarrierFactory.h"
#include<string.h>

#include "bmp\BmpCarrier.h"
#include "jpg\JpgCarrier.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CarrierFactory::CarrierFactory()
{

}

CarrierFactory::~CarrierFactory()
{

}


ICarrier * CarrierFactory::GetCarrier(const char *ext)
{

	ICarrier *p_Carrier = NULL;
	
	if( 0 == stricmp(ext,"bmp"))
	{
		p_Carrier = new BmpCarrier;
	}
	else if( 0 == stricmp(ext,"jpg"))
	{
		p_Carrier = new JpgCarrier;
	}



	return p_Carrier;



}