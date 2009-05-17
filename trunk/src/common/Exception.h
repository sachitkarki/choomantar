# ifndef __EXCEPTION_H
#define __EXCEPTION_H

#include<iostream>
#include<string>

using namespace std;

class Exception
{

public:

	Exception(string ErrorMessage):m_ErrorMessage(ErrorMessage)
	{
	}

	void display();


private:
	string m_ErrorMessage;


};




#endif //End the defination of EXCEPTION.h

