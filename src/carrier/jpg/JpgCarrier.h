// JpgCarrier.h: 
//
//////////////////////////////////////////////////////////////////////

#ifndef __JPG_CARRIER_H_
#define __JPG_CARRIER_H_


#include "..\..\common\CommonDefs.h"

#include "..\Carrier.h"
#include "..\..\common\datainbits.h"
#include "..\..\common\FileManager.h"

class JpgCarrier : public Carrier  
{
public:
	JpgCarrier();
	virtual ~JpgCarrier();

	protected:

    virtual bool canHide(char *carrierFile,char *destFile,char *dataFile);
	virtual bool canUnhide(char *carrierFile,char *dataFile);
	virtual void hideInCarrier(char *carrierFile,char *destFile,char *dataFile);
	virtual void unHideInCarrierFile(char *carrierFile,char *dataFile);
	
	void hideintemp(char *tempfile,char *datafile);
	void unhideintemp(char *tempfile,char *datafile);

};

#endif 
