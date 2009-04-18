#include <stdio.h>
#include "Exception.h"
#include <string.h>

void HandleError(int Error,char* ErrMsg)
{
		switch(Error)
		{

			case IO_CARRIER_FILE_OPEN:
			case D_GIF_OPEN_FAILED:		
					strcpy(ErrMsg,"Cannot Open Carrier File..");
					break;

			case  IO_CARRIER_FILE_CREATE:
			case  E_GIF_OPEN_FAILED:
					strcpy(ErrMsg,"Cannot Create Carrier File..");
					break;

			case IO_CARRIER_FILE:
					strcpy(ErrMsg,"Error Handling Carrier File..");
					break;

			case IO_DATA_FILE_OPEN:
					strcpy(ErrMsg,"Cannot Open Data File..");
					break;

			case IO_DATA_FILE:
					strcpy(ErrMsg,"Error Handling Data File..");
					break;
			case IO_DATA_FILE_CREATE:
					strcpy(ErrMsg,"Cannot Create Data File..");
					break;
			case MEMORY_ALLOC_FAILED:
			case D_GIF_DATA_TOO_BIG:	
			case E_GIF_DATA_TOO_BIG:	
			
			case D_GIF_NOT_ENOUGH_MEM:
			case E_GIF_NOT_ENOUGH_MEM:
			case E_GIF_DISK_IS_FULL:
			case E_GIF_NOT_WRITEABLE:
					strcpy(ErrMsg,"Memory Too Low..Cannot Allocate Momory");
					break;
			case WAVE_NOT_FILE:
					strcpy(ErrMsg,"Not A Wave File");
					break;
			case WAVE_INVALID_CHUNK:
					strcpy(ErrMsg,"Wave File Corrupted");
					break;
			case WAVE_DATACHUNK_NOT_PRESENT:
					strcpy(ErrMsg,"Wave File Corrupted");
					break;
			case WAVE_FILE_NOT_SUPPORTED:
					strcpy(ErrMsg,"Cannot hide data into file");
					break;
			case DATA_TOO_LARGE:
					strcpy(ErrMsg,"Cannot hide data into file:Data Too Large");
					break;
			case PASSWORD_INCORRECT : 
					strcpy(ErrMsg,"Password Incorrect");
					break;
			case IO_SOURCE_OPEN_FILE : 
					strcpy(ErrMsg,"Error Opening Source File");
					break;
			case IO_DEST_OPEN_FILE : 
					strcpy(ErrMsg,"Error Opening Destination File");
					break;
			case IO_ERROR_HANDLING_FILE:
			case D_GIF_READ_FAILED:
			case E_GIF_WRITE_FAILED:
			case D_GIF_NOT_READABLE	:

					strcpy(ErrMsg,"Error Handling Files");
					break;
			case BMP_NOT_FILE:
					strcpy(ErrMsg,"Not A BMP File");
					break;

			case D_GIF_NOT_GIF_FILE	:
					strcpy(ErrMsg,"Not A GIF File");
					break;

			case VALIDATION_FAILED :
			case UNABLE_EXTRACT_DATA :
					strcpy(ErrMsg,"Cannot Retrive Data : Possibly No Data Hidden or Incorrect Password");

				

					break;

			case D_GIF_IMAGE_DEFECT	:
			case D_GIF_EOF_TOO_SOON	:
			case D_GIF_WRONG_RECORD	:
			case D_GIF_NO_SCRN_DSCR	:
			case E_GIF_HAS_SCRN_DSCR:
			case E_GIF_HAS_IMAG_DSCR:
			case E_GIF_NO_COLOR_MAP	:

					strcpy(ErrMsg,"Gif File Corrupted");
					break;

			case E_GIF_CLOSE_FAILED	:
			case D_GIF_CLOSE_FAILED	:
				strcpy(ErrMsg,"Error Closing Gif File..");
					break;

			case SOURCE_FILE_NOT_ENTERED:
				strcpy(ErrMsg,"Source File Not Selected..");
					break;

			case DESTINATION_FILE_NOT_ENTERED:
				strcpy(ErrMsg,"Destination File Not Selected..");
					break;

			case PASSWORD_NOT_ENTERED:
				strcpy(ErrMsg,"Password Not Specified..");
					break;
			case DATA_FILE_NOT_ENTERED:
				strcpy(ErrMsg,"Data File Not Selected..");
					break;
			case FILE_SIZE_NOT_ENTERED:
				strcpy(ErrMsg,"File Size Not Mentioned..");
					break;
			case OUTPUT_FOLDER_NOT_ENTERED:
				strcpy(ErrMsg,"Folder Output Not Mentioned..");
					break;
			case NUMERIC_VALUE_NOT_ENTERED:
				strcpy(ErrMsg,"Value of File Size should be NUMERIC..");
					break;
      
			case JPG_ERROR_FILE_HANDLE:
				strcpy(ErrMsg,"Jpeg File Corrupted..");
					break;
			
			case SPLITTER_FILE_CORRUPT: 
				strcpy(ErrMsg,"Splitter File Corrupted..");
					break;
			
			case SPLITTER_FILE_TO_SMALL:
				strcpy(ErrMsg,"File too Small to Split..");
					break;
	
			case SPLITTER_SOURCE_FILE_NOT_ENTERED: 
				strcpy(ErrMsg,"File to Be Split Not Selected.");
					break;
			
			case SPLITTER_DEST_FILE_NOT_ENTERED:
				strcpy(ErrMsg,"Destination File Not Selected...");
					break;
			case DATA_FILE_CANNOT_HIDE:
				strcpy(ErrMsg,"Cannot Hide the File...");
					break;
			case DATA_FILE_NOT_PRESENT:
				strcpy(ErrMsg,"File Not Present...");
					break;
			case INCORECT_PASWORD_FILE_PATH:
				strcpy(ErrMsg,"Incorrect Password or File Name...");
					break;
			case FLOPPY_INTERNAL_ERROR	:
				strcpy(ErrMsg,"Floppy Internal Error...");
					break;
			case FLOPPY_CANNOT_READ :
				strcpy(ErrMsg,"Error Reading Floppy...");
					break;
			case FLOPPY_CANNOT_WRITE :
				strcpy(ErrMsg,"Error Writing Floppy...");
					break;

			case PASSWORD_SIZE_MORE_EIGHT:
				strcpy(ErrMsg,"Specify Password Less or Equal to 8 characters ...");
					break;

			default:
				strcpy(ErrMsg,"Error......................");
				break;
		}
}