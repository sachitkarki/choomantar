#ifndef __STEGOKEY_H
#define __STEGOKEY_H


#include "CommonDefs.h"

class stegokey
{
protected:
	int n,whichpart;
	BYTE key[8];
public:
	stegokey(int noofbytes);
	stegokey operator ^(stegokey);
	stegokey nextkey();
	int intialize(char *keystring);
	int lenght();
	int converttonum();
	~stegokey();
};


	
#endif  //End of defination of Stego Key