# ifndef __EXCEPTION_H
#define __EXCEPTION_H




#define IO_CARRIER_FILE_OPEN  1
#define IO_CARRIER_FILE		  2
#define IO_DATA_FILE_OPEN     3
#define IO_DATA_FILE		  4
#define IO_DATA_FILE_CREATE	  5
#define MEMORY_ALLOC_FAILED   6
#define IO_CARRIER_FILE_CREATE  7

//Wave Errors

#define WAVE_NOT_FILE				8
#define WAVE_INVALID_CHUNK			9
#define WAVE_DATACHUNK_NOT_PRESENT	10
#define WAVE_FILE_NOT_SUPPORTED		11

//RC6 Error
#define PASSWORD_INCORRECT		12
#define IO_SOURCE_OPEN_FILE     13
#define IO_DEST_OPEN_FILE		14
#define IO_ERROR_HANDLING_FILE  15


//Bmp Error
#define BMP_NOT_FILE 16

//Text Error 



//General
#define DATA_TOO_LARGE		17
#define VALIDATION_FAILED   18
#define UNABLE_EXTRACT_DATA	19

//Jpeg Error
#define JPG_ERROR_FILE_HANDLE 20

//Splitter Error
#define SPLITTER_FILE_CORRUPT			 21
#define SPLITTER_FILE_TO_SMALL			 22
#define SPLITTER_SOURCE_FILE_NOT_ENTERED 23
#define SPLITTER_DEST_FILE_NOT_ENTERED   24

//Floppy Errors
#define DATA_FILE_CANNOT_HIDE	   25
#define DATA_FILE_NOT_PRESENT	   26
#define INCORECT_PASWORD_FILE_PATH 27
#define FLOPPY_INTERNAL_ERROR      28
#define FLOPPY_NOT_DETECTED        29
#define FLOPPY_CANNOT_READ         30
#define FLOPPY_CANNOT_WRITE        31


// Gif Errors


#define	E_GIF_OPEN_FAILED	201			/* EGif possible errors. */
#define	E_GIF_WRITE_FAILED	202
#define E_GIF_HAS_SCRN_DSCR	203
#define E_GIF_HAS_IMAG_DSCR	204
#define E_GIF_NO_COLOR_MAP	205
#define E_GIF_DATA_TOO_BIG	206
#define E_GIF_NOT_ENOUGH_MEM 207
#define E_GIF_DISK_IS_FULL	208
#define E_GIF_CLOSE_FAILED	209
#define E_GIF_NOT_WRITEABLE	210


#define	D_GIF_OPEN_FAILED	101		/* And DGif possible errors. */
#define	D_GIF_READ_FAILED	102
#define	D_GIF_NOT_GIF_FILE	103
#define D_GIF_NO_SCRN_DSCR	104
#define D_GIF_NO_IMAG_DSCR	105
#define D_GIF_NO_COLOR_MAP	106
#define D_GIF_WRONG_RECORD	 107
#define D_GIF_DATA_TOO_BIG	 108
#define D_GIF_NOT_ENOUGH_MEM 109
#define D_GIF_CLOSE_FAILED	110
#define D_GIF_NOT_READABLE	111
#define D_GIF_IMAGE_DEFECT	112
#define D_GIF_EOF_TOO_SOON	113

//Gui Errors

#define SOURCE_FILE_NOT_ENTERED			300
#define DESTINATION_FILE_NOT_ENTERED	301
#define PASSWORD_NOT_ENTERED			302
#define DATA_FILE_NOT_ENTERED			303
#define FILE_SIZE_NOT_ENTERED			304
#define OUTPUT_FOLDER_NOT_ENTERED		305
#define NUMERIC_VALUE_NOT_ENTERED		306
#define PASSWORD_SIZE_MORE_EIGHT        307
       

void HandleError(int Error,char*ErrorMsg);

#endif //End the defination of EXCEPTION.h

