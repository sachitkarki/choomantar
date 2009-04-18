// BmpCarrier.h: interface for the BmpCarrier class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __BMP_CARRIER_H_
#define __BMP_CARRIER_H_


#include "..\..\common\CommonDefs.h"

#include "..\Carrier.h"
#include "..\..\common\datainbits.h"
#include "..\..\common\FileManager.h"


class BmpCarrier : public Carrier  
{
public:
	BmpCarrier();
	virtual ~BmpCarrier();
protected:
    virtual bool canHide(char *carrierFile,char *destFile,char *dataFile);
	virtual bool canUnhide(char *carrierFile,char *dataFile);
	virtual void hideInCarrier(char *carrierFile,char *destFile,char *dataFile);
	virtual void unHideInCarrierFile(char *carrierFile,char *dataFile);

	//Added Members
	
	unsigned int imageSize,imageOffset,noOfRegions;
	FileManager carrier;
	datainbits inputData;
	unsigned int dataLength;
	bool isSignatureBmp();

	//

};

#endif