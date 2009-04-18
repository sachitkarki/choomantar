#include <stdio.h>
#include "data.h"

/* whenever you want to get data from a file open file using this function.
this returns true on success and false on error
*/
bool data::openforread(char *filename)
{
	return	datafile.Open(filename,ReadMode);
}

/* whenever you want to writedata to a file open file using this function.
this returns true success and false on error
*/

bool data::openforwrite(char *filename)
{
return	datafile.Open(filename,ReadWriteCreateMode);
	
}


/* whenever you want to writedata to a file use this function.
this returns 0 on faliure */

unsigned int data::putdata(int from,int howmany,BYTE *buff)
{
	
	datafile.Seek(from,BeginSeek);
	return datafile.Write(buff,howmany);
}



/* whenever you want to read from a file use this function.
this returns  0 on faliure 
it takes which is the starting byte howmany bytes and buffer
and pointer to an int of howmany bytes read 
This is zero if the file is at end and yuo are trying to read
check this for end of file
This also puts the signature JSA int the input
*/

unsigned int data::getdata(int from,int howmany,BYTE *buff,int *howmanyread)
{
 int i=0,lenght;
 lenght=datafile.GetLength();
 
	switch(from)
	{
	case 0:
		buff[i++]='J';
	case 1:
		buff[i++]='S';
	case 2:
		buff[i++]='A';

	}
	
		if(i!=0)
		{
			datafile.Seek(0,BeginSeek);
		*howmanyread=datafile.Read(buff+i,howmany-i)+i;
		}
		else
		{
			from=from-3;
			datafile.Seek(from,BeginSeek);
		*howmanyread=datafile.Read(buff+i,howmany-i);
		}


	
	

	return *howmanyread;
}

/* this gives the lenght + 3 for signature*/

unsigned int data::length()
{
	return datafile.GetLength()+3;
}


/*this is same as getdata function but does no put the siganature*/
unsigned int data::getdataforwrite(int from,int howmany,BYTE *buff,int *howmanyread)
{
 
	
			datafile.Seek(from,BeginSeek);
		*howmanyread=datafile.Read(buff,howmany);



	return *howmanyread;
}


void data::close()
{

datafile.Close();	

}
