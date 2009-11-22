#include "CommandArgs.h"
#include <string.h>
#include <stdlib.h>
#include "..\common\Exception.h"

CommandArgs::CommandArgs(int argc,char*argv[]){

noOfArguments = argc;
char* opt = "-s";
char* inp = "-i";
char* op = "-o";
char* data = "-d";
char*pa = "-p";


	for(int i=1;i<argc;i++){

		if(!strcmp(argv[i],opt)){

			option = (char *)malloc(strlen(argv[i+1]+1));
			strcpy(option,argv[i+1]);
			i++;
		}

		if(!strcmp(argv[i],inp)){

			inputCarrier =(char *) malloc(strlen(argv[i+1]+1));
			strcpy(inputCarrier,argv[i+1]);
			i++;
		}
		
		if(!strcmp(argv[i],op)){

			outputCarrier =(char *) malloc(strlen(argv[i+1]+1));
			strcpy(outputCarrier,argv[i+1]);
			i++;
		}


		if(!strcmp(argv[i],data)){

			dataFile = (char *)malloc(strlen(argv[i+1]+1));
			strcpy(dataFile,argv[i+1]);
			i++;
		}
	
		
		if(!strcmp(argv[i],pa)){
		
			pass =(char *)malloc(strlen(argv[i+1]+1));
			strcpy(pass,argv[i+1]);
			i++;
		}

	}

}


int CommandArgs::getOptions()
{

	if(runCount ==1){
	return EXIT;
	}

	if(!strcmp(option,"hide")){
		runCount =1;
		return HIDE;
	}


	if(!strcmp(option,"unhide")){
		runCount =1;
		return UNHIDE;
	}
	
	if(strcmp(option,"hide") && strcmp(option,"unhide")){
		throw new Exception("Invalid / Incorrect option specified.");
	}

//throw a exception if its not any;
return EXIT;
}

bool CommandArgs::getDataForHide(char*inputFileName , char*outputFileName,char*dataFileName,char*password)
{
//need to coolect all expections and throw at once

	if(!inputCarrier){
		throw new Exception("Input Carrier file not specified");
	}

	if(!outputCarrier){
		throw new Exception("Output Carrier  file not specified");
	}

	if(!dataFile){
		throw new Exception("Data file not specified");
	}

	if(!pass){
		throw new Exception("Password not specified");
	}
			
	strcpy(inputFileName , inputCarrier);
	strcpy(outputFileName,outputCarrier);
	strcpy(dataFileName,dataFile);
	strcpy(password,pass);
	
return true;
}


bool CommandArgs::getDataForUnHide(char*inputFileName,char*outputDataFileName,char*password)
{

	if(!inputCarrier){
		throw new Exception("Input Carrier file not specified");
	}
	
	if(!dataFile){
		throw new Exception("Data file not specified");
	}

	if(!pass){
		throw new Exception("Password not specified");
	}
			
	strcpy(inputFileName , inputCarrier);
	strcpy(outputDataFileName,dataFile);
	strcpy(password,pass);

	
	return true;
				

}
