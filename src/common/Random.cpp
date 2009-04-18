#include <stdio.h>
#include "Random.h"
//this is a function to get the prime number
unsigned long RandomGenerator :: prime(unsigned long x)
{
	unsigned long   y,z,l,b;
	z=1;y=1;l=0;b=0;
		for(unsigned long i=1;i<=x;i++)	
		{
			
			unsigned long f=(unsigned long)sqrt(i);
			for(z=1;z<=f;z++) 	
			{  
				y=i%z;
				if(y==0)
				    l++;
					
				if(l>=2)
					break;
			}

				
			if (l<=1)  
			{
				b=i;
			}

			l=0;
		}
	return b;
}

//function to generate the relative prime number  
unsigned long RandomGenerator :: Get_Relative(unsigned long num)
{
    unsigned long counter=0,sed=I1;
    
    while(counter<(range-(range%10)))
    {
		counter=0;
		num=num-1;
		sed=((num*I1))%range;
		I1=sed;

		do
		{
			counter++;
		    I1=((num*I1))%range;
		
		}while(sed!=I1);
    }

    return num;
}


//this function is called everytime u want to have new set of random nos.
void RandomGenerator :: setRangeAndSeed(unsigned long seed_1,unsigned long range_1)
{
	range = range_1;//get the actual range
	range = prime(range);// get the prime number for range
	I1 = seed_1;// set I1 to seed for formula
	
	A = Get_Relative(42);// get the relative prime number
	count = 0;//initialize counter to zero

}
//generates random  number
unsigned long RandomGenerator :: RandomNG()
{
	/*
	The Formula for Random Number Generator is as follows
	I2=A*I1+C mod range
	I1 -> is Your seed and I2 is ur random number
	This is how it works when we generate the series
	then for ever nex number to be generated the previous number
	generated is ur seed.
	A & range are constants but following condtion must be met
	Imp: A and range should be realtive prime nos reason to get a
	full period LCG i.e. no nubers are repeated  till all the nos
	are visited. this means ur range is ur range i.e. if u want range
	from 1 - 400, then range sould be the closest prime number to 400.

	C is set to zero in general except when I2!=0 & I1=0*/
			
	C = 0;
	if( count > range-1)
			return 0;
		
	   I1 = ( (A*I1) + C ) % range; // this is formula for LCG PseudoRandom number generator
	
	   
	   count++;

	   return I1;

}
//once initialised Range and seed using setRangeAndSeed
//use this function to get a random number incrementally

unsigned long RandomGenerator :: nextRandom()
{
	
	unsigned long ret = RandomNG();

	return ret;

}

int RandomGenerator::getRange()
{
	
	return range;
}