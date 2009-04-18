#include <stdio.h>
#include "datainbits.h"
datainbits::datainbits()
{
from=-1;
to=-1;
maxbyte=-1;
}

/*
here after you have opened the file using openforread()
you can pass the bitno you want.
the bits are lsb first
i.e bit 0 of byte 0 is bitno 0 and bit 1 of byte 0 is bitno 1

  This return 0 if bit is zero
  -1 if error
  non zero if 1
*/




int datainbits::getBitNo(int n)
{
	int byteno,bitno,howmanyread;

	byteno=n>>3;
	bitno=n&0x7;




	if(byteno<from || byteno>=to||from==-1)
	{
		getdata(byteno,512,buffread,&howmanyread);

		if(howmanyread==0)
			return -1;
		from=byteno;
		to=from+howmanyread;
	}

    return buffread[byteno-from] & (BYTE)(1<<bitno); 
	

}


/*
here after you have opened the file using openforwrite()
you can pass the bitno you want to write and value 1 or 0
the bits are lsb first
i.e bit 0 of byte 0 is bitno 0 and bit 1 of byte 0 is bitno 1

 it returns the value back
*/

int datainbits::putBitNo(int n,int value)
{
int byteno,bitno,howmanyread=0;

	byteno=n>>3;
	bitno=n&0x7;

	BYTE t;

//	maxbyte=(byteno>maxbyte?byteno:maxbyte);

	datafile.Seek(byteno,BeginSeek);
	datafile.Read(&t,1);

	if(value==1)
		t =t | (BYTE)(1<<bitno);
	else if (value==0)
	{
		BYTE temp= (BYTE) 0xfe;
		for(int i=0;i<bitno;i++)
		{
			temp<<=1;
			temp|=1;
		}
	t  = t & temp;
	}

	datafile.Seek(byteno,BeginSeek);
	datafile.Write(&t,1);

return value;


}

/* this is to flush the buffer. As data is stored in buffer
you need to flush it after finishinging writing
return -1 on error
*/ 

int datainbits::flushBuff()
{
/*if(to>maxbyte)
	to=maxbyte;

 if(0==putdata(from,to-from+1,buffread))
				return -1;
*/

 datafile.Flush();
 return 0;
}

