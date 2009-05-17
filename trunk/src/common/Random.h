#ifndef __RANDOM_H
#define __RANDOM_H


#include<iostream>
#include<stdio.h>
#include<conio.h>

#include<math.h>

using namespace std;

class RandomGenerator
{
protected:
		//function to generate prime number
	unsigned long prime(unsigned long range_1);

	/*
	using LCG random number generator
	*/

protected:

	unsigned long range,count,I1;
	unsigned long A,C;
	unsigned long RandomNG();// seed is provide by user it can be
						  //any number other than zero
	unsigned long RandomGenerator :: Get_Relative(unsigned long num);

	int getRange();

public:
	// use this function to provide the range and seed only in the
	//beginnin of callin random number generator there after use
	// NextRandom() to get the random numbers
	void setRangeAndSeed(unsigned long seed_1,unsigned long range_1);
	unsigned long nextRandom();


};


#endif //End of defination of Random Generator


