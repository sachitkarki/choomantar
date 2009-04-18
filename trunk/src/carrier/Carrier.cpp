// Carrier.cpp: implementation of the Carrier class.
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "Carrier.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Carrier::Carrier()
{
	m_pStegoKey = NULL;
}

Carrier::~Carrier()
{
	if(m_pStegoKey)
		delete m_pStegoKey;
}

void Carrier::setKey(char *key) 
{

	int len = 0;
	len = strlen(key);
	
	if(m_pStegoKey) 
		delete m_pStegoKey;

	m_pStegoKey = new stegokey(len);
	m_pStegoKey->intialize(key);


}
void Carrier::hide(char *carrierFile,char *destFile,char *dataFile) 
{

	if( canHide(carrierFile,destFile,dataFile) )
	{
		hideInCarrier(carrierFile,destFile,dataFile);
	}
}

void Carrier::unHide(char *carrierFile,char *dataFile) 
{

	if( canUnhide(carrierFile,dataFile) )
	{
		unHideInCarrierFile(carrierFile,dataFile);
	}

}

bool Carrier::canHide(char *carrierFile,char *destFile,char *dataFile)
{
	return true;
}

bool Carrier::canUnhide(char *carrierFile,char *dataFile) 
{
	return true;
}