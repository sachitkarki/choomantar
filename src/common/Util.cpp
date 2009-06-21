#include "Util.h"
#include  "string.h"


char * Util::getExtensionFromfilename(char *fileName)
{
	
	int len = strlen(fileName);
	char *pch = fileName + len -1; // Point to last char of the file name

	while(*pch !='.')
	{
		pch--;
	}

 return pch + 1;	

}