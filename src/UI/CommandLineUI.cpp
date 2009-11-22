#include "CommandLineUI.h"
#include<iostream.h>


int CommandLineUI::getOptions()
{

int ch;


	cout<<"\n1.)Hide\n2.)Unhide\n0.)Exit\nEnter Your choice : \t";
	cin>>ch;


return ch;
}

bool CommandLineUI::getDataForHide(char*inputFileName , char*outputFileName,char*dataFileName,char*password)
{


				cout<<"\nEnter the input carrier file (File to in which to hide): \t";
				cin>>inputFileName;
				cout<<"\nEnter the output file : \t";
				cin>>outputFileName;
				cout<<"\nEnter the data  file (File which to hide): \t";
				cin>>dataFileName;
				cout<<"\nEnter the password: \t";
				cin>>password;
			
				
				
				//Use only for testing purpose
				/*
				strcpy(input,"c:\\a.bmp");
				strcpy(output,"c:\\oa.bmp");
				strcpy(data,"c:\\a.txt");
				strcpy(password,"aaaa");
				
				*/

return true;
}


bool CommandLineUI::getDataForUnHide(char*inputFileName,char*outputDataFileName,char*password)
{

	
				cout<<"\nEnter the input carrier file (File from  which to unhide data): \t";
				cin>>inputFileName;
				cout<<"\nEnter the data  file (File which will store the data which was hidden: \t";
				cin>>outputDataFileName;
				cout<<"\nEnter the password \t";
				cin>>password;
			

				
				//Use only for testing purpose
				/*
				strcpy(input,"c:\\a.bmp");
				//strcpy(output,"c:\\oa.txt");
				strcpy(data,"c:\\ao.txt");
				strcpy(password,"aaaa");
				*/
				
return true;
}