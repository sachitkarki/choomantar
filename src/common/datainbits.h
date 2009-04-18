#ifndef __DATAINBITS_H
#define __DATAINBITS_H

#include "data.h"
class datainbits:public data
{
protected:
	BYTE buffread[512];
	int from,to,maxbyte;
public:
	datainbits();
	int getBitNo(int n);	
	int putBitNo(int n,int value);
	int flushBuff();

};


#endif