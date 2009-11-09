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
	int t = 0;
	int finalNum = 0;
	int i;
	for( i=0; i< n ; i++ )
	{
		
		if( i % 4 ==0 )
		{
			finalNum = finalNum ^ t ;
		}
		
		t<<=8;
		t = t | key[i];
	}
	
	if( n%4 !=0 )
		finalNum = finalNum ^ t ;
	
	return finalNum;
	
}



stegokey::~stegokey()
{
	//	delete[] key;
}


