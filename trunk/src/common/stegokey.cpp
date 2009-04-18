#include <stdio.h>

#include "stegokey.h"
#include "CommonDefs.h"

stegokey::stegokey(int noofbytes)
{
	n=noofbytes;
//	key=new BYTE[n];

}

stegokey stegokey::operator ^(stegokey otherkey)
{
	stegokey temp(n);
	for(int i=0;i<n;i++)
		temp.key[i]=key[i] ^ otherkey.key[i];

	return temp;
}

int stegokey::intialize(char *keystring)
{
	for(int i=0;i<n;i++)
		key[i]=(BYTE)keystring[i];
whichpart=0;
return 1;
}
int stegokey::lenght()
{
	return n;
}
int stegokey::converttonum()
{
	int t=0;
	if(whichpart==0)
	{
		for(int i=0;i<4;i++)
		{
			t<<=8;
			t|=key[i];
		}
	whichpart=1;
	}
	else
	{
		for(int i=4;i<8;i++)
		{
			t<<=8;
			t|=key[i];
		}
	whichpart=0;




	}
return t;
}



stegokey::~stegokey()
{
//	delete[] key;
}


