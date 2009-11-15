//  Defines the entry point for the console application.
//


#include <string.h>
#include ".\carrier\ICarrier.h"
#include ".\carrier\CarrierFactory.h"
#include ".\common\Exception.h"
#include ".\common\Signature.h"
#include ".\common\Util.h"
#include ".\UI\IUserInterface.h"
#include ".\UI\CommandLineUI.h"
#include ".\UI\CommandArgs.h"


using namespace std;


void hideDataInCarrier(char*inputFileName , char*outputFileName,char*dataFileName,char*password){

	ICarrier *p_Carrier = NULL;
	p_Carrier = CarrierFactory::GetCarrier(Util::getExtensionFromfilename(inputFileName));

	if(p_Carrier)
	{
			
		p_Carrier->setKey(password);
		p_Carrier->hide(inputFileName,outputFileName,dataFileName);
		delete p_Carrier;

	}
}


void unhideDateFromCarrier(char* inputFileName ,  char* outputDataFileName ,  char * password){
	ICarrier *p_Carrier = NULL;
	
	p_Carrier = CarrierFactory::GetCarrier(Util::getExtensionFromfilename(inputFileName));
	
	if(p_Carrier)
	{
	
		p_Carrier->setKey(password);
		p_Carrier->unHide(inputFileName,outputDataFileName);
		removesignature(outputDataFileName);
		delete p_Carrier;
	}

}


void exec(IUserInterface *userInterface){


	int ch = -1;
	char input[100],output[100],password[100],data[100];

	do
	{

			ch = userInterface->getOptions();
			switch(ch)
			{
			case HIDE:
				userInterface->getDataForHide(input,output,data,password);
				hideDataInCarrier(input,output,data,password);			
				break;

			case UNHIDE:
			

				userInterface->getDataForUnHide(input,data,password);
				unhideDateFromCarrier(input,data,password);
				break;

			case EXIT:

				break;
			}

			//TODO: need to check if the userINterface is CommangArgs then exit;


	}while(ch != 0);
}


int main(int argc, char* argv[])
{

IUserInterface *userInterface;

	try{

		if(argc  > 1){
			userInterface = new CommandArgs(argc,argv);
			//ran thru cmd
			
		}else{
			userInterface = new CommandLineUI();
			
		}

		exec(userInterface);

	}catch(Exception *vl_Exception)
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

return 0;
}

//-s unhide -i c:\b.bmp  -d c:\c.txt -p amruta