//  Defines the entry point for the console application.
//

#include<iostream>
#include <string.h>
#include ".\carrier\ICarrier.h"
#include ".\carrier\CarrierFactory.h"
#include ".\common\Exception.h"
#include ".\common\Signature.h"

using namespace std;

char *getExtensionFromfilename(char *fileName)
{
	
	int len = strlen(fileName);
	char *pch = fileName + len -1; // Point to last char of the file name

	while(*pch !='.')
	{
		pch--;
	}

 return pch + 1;	

}
int main(int argc, char* argv[])
{

	
	char ch = 1;
	char input[100],output[100],password[100],data[100];
	ICarrier *p_Carrier = NULL;
	while(ch != '0')
	{

		try
		{
			cout<<"\n1.)Hide\n2.)Unhide\n0.)Exit\nEnter Your choice :";
			cin>>ch;

			switch(ch)
			{
			case '1':
				
				cout<<"\nEnter the input carrier file (File to in which to hide):";
				cin>>input;
				cout<<"\nEnter the output file :";
				cin>>output;
				cout<<"\nEnter the data  file (File which to hide):";
				cin>>data;
				cout<<"\nEnter the password";
				cin>>password;
								 

				
				//Use only for testing purpose
				/*
				strcpy(input,"c:\\a.bmp");
				strcpy(output,"c:\\oa.bmp");
				strcpy(data,"c:\\a.txt");
				strcpy(password,"aaaa");
				
				*/

				p_Carrier = CarrierFactory::GetCarrier(getExtensionFromfilename(input));

				if(p_Carrier)
				{
					
					p_Carrier->setKey(password);
					p_Carrier->hide(input,output,data);
					delete p_Carrier;

				}
				break;

			case '2':
			

			
				cout<<"\nEnter the input carrier file (File from  which to unhide data):";
				cin>>input;
				cout<<"\nEnter the data  file (File which will store the data which was hidden:";
				cin>>data;
				cout<<"\nEnter the password";
				cin>>password;
			

				
				//Use only for testing purpose
				/*
				strcpy(input,"c:\\a.bmp");
				//strcpy(output,"c:\\oa.txt");
				strcpy(data,"c:\\ao.txt");
				strcpy(password,"aaaa");
				*/
				

				p_Carrier = CarrierFactory::GetCarrier(getExtensionFromfilename(input));

				if(p_Carrier)
				{
					
					p_Carrier->setKey(password);
					p_Carrier->unHide(input,data);
					removesignature(data);
					delete p_Carrier;

				}
				break;

			case '0':

				break;
			}
		}
		catch(Exception *vl_Exception)
		{
			
			vl_Exception->display();
			delete vl_Exception;
		}
		catch(...)
		{
			Exception *unhandledException = new Exception("A runtime exception has occured");
			unhandledException->display();
			delete unhandledException;

		}

	}

	return 0;
}

