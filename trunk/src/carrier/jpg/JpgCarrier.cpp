// JpgCarrier.cpp: implementation of the JpgCarrier class.
//
//////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include<stdlib.h>
// As FAR is defined in <windows.h> and jconfig.h needs this defination.
#define FAR  

typedef unsigned short WORD;
//------------------------------------------------------------------
#include "JpgCarrier.h"
#include "..\..\common\Random.h"

extern "C"
{
#include "jpeglib.h"
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



void myerror(j_common_ptr cinfo)
{
	
}


JpgCarrier::JpgCarrier()
{

}

JpgCarrier::~JpgCarrier()
{

}

bool JpgCarrier::canHide(char *carrierFile,char *destFile,char *dataFile)
{

	bool breturnValue = true;

	return breturnValue;

}

bool JpgCarrier::canUnhide(char *carrierFile,char *dataFile)
{

	bool breturnValue = true;	

	return breturnValue;

}

	
void JpgCarrier::hideInCarrier(char *carrierFile,char *destFile,char *dataFile)
{

	struct jpeg_decompress_struct srcinfo,*ptrsrcinfo;
	struct jpeg_compress_struct dstinfo,*ptrdstinfo;

	jvirt_barray_ptr * src_coef_arrays;
	struct jpeg_error_mgr jsrcerr, jdsterr;


	JDIMENSION dst_blk_x, dst_blk_y;
	int ci, i, offset_x, offset_y;
	JBLOCKARRAY  dst_buffer;
	JCOEFPTR  dst_ptr;
	jpeg_component_info *compptr;

	FileManager temp;
	short int t;

	FILE * input_file;
	FILE * output_file;


	srcinfo.err = jpeg_std_error(&jsrcerr);
	jsrcerr.error_exit =myerror;

	jpeg_create_decompress(&srcinfo); // Create Decompress Object 




	/* Open the input file. */

	if ((input_file = fopen(carrierFile, "rb")) == NULL) {
		return;
	  //throw IO_CARRIER_FILE_OPEN;      
	}



	/* Specify data source for decompression */
	jpeg_stdio_src(&srcinfo, input_file);

	/* Enable saving of extra markers that we want to copy */
	// jcopy_markers_setup(&srcinfo, copyoption);

	/* Read file header */
	(void) jpeg_read_header(&srcinfo, TRUE);


	/* Read source file as DCT coefficients */
	src_coef_arrays = jpeg_read_coefficients(&srcinfo);



	//fclose(temp);


	


	ptrsrcinfo=&srcinfo;

	if(!temp.Open("jsa.jsa",ReadWriteCreateMode))
	{
		//throw IO_ERROR_HANDLING_FILE;

	}





	for (ci = 0; ci < ptrsrcinfo->num_components  ; ci++)//for component
	{
	compptr = ptrsrcinfo->comp_info + ci;

		for (dst_blk_y = 0; dst_blk_y < compptr->height_in_blocks ;dst_blk_y += compptr->v_samp_factor) //for block
		{
		  dst_buffer = (*ptrsrcinfo->mem->access_virt_barray)
		((j_common_ptr) ptrsrcinfo, src_coef_arrays[ci], dst_blk_y,
		 (JDIMENSION) compptr->v_samp_factor, TRUE);
			  for (offset_y = 0; offset_y < compptr->v_samp_factor  ; offset_y++) 
			  {
					for (dst_blk_x = 0; dst_blk_x < compptr->width_in_blocks  ;dst_blk_x += compptr->h_samp_factor) 
					{
				
							for (offset_x = 0; offset_x < compptr->h_samp_factor  ; offset_x++) 
							{
						
								dst_ptr = dst_buffer[offset_y][dst_blk_x + offset_x];
								temp.Write(dst_ptr,64 *2);
								
							}	
					}

				}
		}
	}

	temp.Close();

	hideintemp("jsa.jsa",dataFile);

	dstinfo.err = jpeg_std_error(&jdsterr);
	jdsterr.error_exit =myerror;



	jpeg_create_compress(&dstinfo);// Create Decompress Object 
	/* Specify data destination for compression */
	
	if ((output_file = fopen(destFile, "wb")) == NULL) 
	{
		return;
	//  throw IO_DATA_FILE_CREATE;
	}

	jpeg_stdio_dest(&dstinfo, output_file);
	jpeg_copy_critical_parameters(&srcinfo, &dstinfo);
		ptrdstinfo=&dstinfo;

	if(!temp.Open("jsa.jsa",ReadMode))
	{
		return;
		//throw IO_ERROR_HANDLING_FILE;

	}




	for (ci = 0; ci < ptrsrcinfo->num_components  ; ci++)//for component
	{
		compptr = ptrsrcinfo->comp_info + ci;

		for (dst_blk_y = 0; dst_blk_y < compptr->height_in_blocks ;dst_blk_y += compptr->v_samp_factor) //for block
		{
		  dst_buffer = (*ptrsrcinfo->mem->access_virt_barray)
		((j_common_ptr) ptrsrcinfo, src_coef_arrays[ci], dst_blk_y,
		 (JDIMENSION) compptr->v_samp_factor, TRUE);
			  for (offset_y = 0; offset_y < compptr->v_samp_factor  ; offset_y++) 
			  {
					for (dst_blk_x = 0; dst_blk_x < compptr->width_in_blocks  ;dst_blk_x += compptr->h_samp_factor) 
					{
				
							for (offset_x = 0; offset_x < compptr->h_samp_factor  ; offset_x++) 
							{
								dst_ptr = dst_buffer[offset_y][dst_blk_x + offset_x];
								for(i=0;i<64;i++)
								{
									temp.Read(&t,2);
									dst_ptr[i] =t;

								}
								
							}	
					}

				}
		}
	}


	jpeg_write_coefficients(&dstinfo,src_coef_arrays);



	/* Finish compression and release memory */

	jpeg_finish_compress(&dstinfo);
	jpeg_destroy_compress(&dstinfo);
	(void) jpeg_finish_decompress(&srcinfo);
	jpeg_destroy_decompress(&srcinfo);

	/* Close files, if we opened them */
	if (input_file)
		fclose(input_file);
	if (output_file )
		fclose(output_file);


	temp.Close();

	FileManager::Remove("jsa.jsa");

	
}

void JpgCarrier::unHideInCarrierFile(char *carrierFile,char *dataFile)
{

	struct jpeg_decompress_struct srcinfo,*ptrsrcinfo;

jvirt_barray_ptr * src_coef_arrays;
  struct jpeg_error_mgr jsrcerr;

  
	JDIMENSION dst_blk_x, dst_blk_y;
  int ci, offset_x, offset_y;
  JBLOCKARRAY  dst_buffer;
  JCOEFPTR  dst_ptr;
  jpeg_component_info *compptr;

  FileManager temp;
	

  FILE * input_file;
  


   srcinfo.err = jpeg_std_error(&jsrcerr);
   jsrcerr.error_exit =myerror;


   jpeg_create_decompress(&srcinfo);

    if ((input_file = fopen(carrierFile, "rb")) == NULL) 
	{
      //throw IO_CARRIER_FILE_OPEN;      
		return;
    }


	 jpeg_stdio_src(&srcinfo, input_file);

  /* Enable saving of extra markers that we want to copy */
// jcopy_markers_setup(&srcinfo, copyoption);

  /* Read file header */
  (void) jpeg_read_header(&srcinfo, TRUE);
   src_coef_arrays = jpeg_read_coefficients(&srcinfo);
   ptrsrcinfo=&srcinfo;



   if(!temp.Open("jsa.jsa",ReadWriteCreateMode))
  {
		//throw IO_ERROR_HANDLING_FILE;
	   return;

  }


  
  
  
  for (ci = 0; ci < ptrsrcinfo->num_components  ; ci++)//for component
  {
    compptr = ptrsrcinfo->comp_info + ci;

    for (dst_blk_y = 0; dst_blk_y < compptr->height_in_blocks ;dst_blk_y += compptr->v_samp_factor) //for block
	{
      dst_buffer = (*ptrsrcinfo->mem->access_virt_barray)
	((j_common_ptr) ptrsrcinfo, src_coef_arrays[ci], dst_blk_y,
	 (JDIMENSION) compptr->v_samp_factor, TRUE);
		  for (offset_y = 0; offset_y < compptr->v_samp_factor  ; offset_y++) 
		  {
				for (dst_blk_x = 0; dst_blk_x < compptr->width_in_blocks  ;dst_blk_x += compptr->h_samp_factor) 
				{
			
						for (offset_x = 0; offset_x < compptr->h_samp_factor  ; offset_x++) 
						{
					//	src_ptr = src_buffer[offset_x][dst_blk_y + offset_y];
						dst_ptr = dst_buffer[offset_y][dst_blk_x + offset_x];
						temp.Write(dst_ptr,64 *2);
							
						}	
				}

			}
    }
  }

  temp.Close();


  unhideintemp("jsa.jsa",dataFile);

		
  FileManager::Remove("jsa.jsa");


}




void JpgCarrier::hideintemp(char *tempfile,char *datafile)
{

	FileManager carrier;
	int imagesize,noofregions;

WORD buff[REGION_SIZE];
//	char temp[20];
	RandomGenerator r;  
//	ran r;
	int i,noofbytesread,lenght;
	int imageoffset=0;

	//stegokey key(4);
//	key.intialize(pass);

	datainbits inputdata;


	
	



	if(!carrier.Open(tempfile,ReadWriteMode))
	{
			//throw IO_ERROR_HANDLING_FILE;
		return;
	}

	if(!inputdata.openforread(datafile))
	{
		//throw IO_DATA_FILE_OPEN;
		return;
	}

	
	imagesize=carrier.GetLength()-64;   //32 left for lenght
		noofregions=imagesize/REGION_SIZE;
		if(imagesize%REGION_SIZE!=0)
			noofregions++;


			if(inputdata.length()> imagesize/24)//dct are words
			{
				inputdata.close();
				carrier.Close();
				//throw DATA_TOO_LARGE;//data too big to filt in

			}



	carrier.Seek(imageoffset,BeginSeek);
	carrier.Read(buff,32*2);//32 dcts
	lenght=inputdata.length();
	for(i=0;i<32;i++)    //store the lenght
	{
		int k=1<<i;

		k=k&lenght;
			if(k==0)
				buff[i]=buff[i] & 0xfffe;
			else
				buff[i]=buff[i] | 1;
	}
	

	carrier.Seek(imageoffset,BeginSeek);
	carrier.Write(buff,32*2);

	imageoffset+=64;




	for( i=0;i<noofregions;i++)
	{
		int z=i*REGION_SIZE+imageoffset;
		carrier.Seek(i*REGION_SIZE+imageoffset,BeginSeek);
		noofbytesread=carrier.Read(buff,REGION_SIZE);
		r.setRangeAndSeed(m_pStegoKey->converttonum(),noofbytesread/2);//because dct is 2 bytes
		int t=0,bitno=i,byteno;




//		byteno=0;//change
	
		while(t!=-1)
				//	while(byteno<noofbytesread)
		{
			t=inputdata.getBitNo(bitno);
			byteno=r.nextRandom();
				if(t==-1)
					break;
				else if (t==0)
						buff[byteno]&=0xfffe;
				else
						buff[byteno]|=1;
		//		bitno++;
			bitno+=noofregions;
					//byteno++;
		}
		carrier.Seek(i*REGION_SIZE+imageoffset,BeginSeek);
		carrier.Write(buff,noofbytesread);
	/*
		nextkey=key^prevkey;
		prevkey=key;
		key=nextkey;*/


	
	}

	carrier.Close();
	inputdata.close();












	

}
void JpgCarrier::unhideintemp(char *tempfile,char *datafile)
{
	
FileManager carrier;

datainbits inputdata;
int imagesize,imageoffset=0,noofbytesread;
WORD buff[512];

//stegokey key(4);
RandomGenerator r;

//key.intialize(pass);








  if(!carrier.Open(tempfile,ReadWriteMode))
  {
	  //throw IO_ERROR_HANDLING_FILE;
	  return;

  }

  if(!inputdata.openforwrite(datafile))
  {
	  return;
	//			throw  IO_DATA_FILE_CREATE;    //data file cannot be opened
  }


	

  	imagesize=carrier.GetLength()-64; //size in first 32 bytes
	int 	noofregions=imagesize/REGION_SIZE;
		if(imagesize%REGION_SIZE!=0)
			noofregions++;
		carrier.Seek(imageoffset,BeginSeek);
		carrier.Read(buff,32*2);
int 	datalenght=0;
	int t1,t;
		for(int i=0;i<32;i++)
		{
			t=1<<i;

			t1=buff[i] & 1;
			if(t1!=0)
				datalenght  =t|datalenght;
		}
		imageoffset+=64;

int	totaldatabits=8*datalenght;




		for( i=0;i<noofregions;i++)
		{
		int z=i*REGION_SIZE+imageoffset;
		carrier.Seek(i*REGION_SIZE+imageoffset,BeginSeek);
		noofbytesread=carrier.Read(buff,REGION_SIZE);
		r.setRangeAndSeed(m_pStegoKey->converttonum(),noofbytesread/2);
		int t=0,bitno=i,byteno=0;
		while(bitno<totaldatabits)
		{
			
			byteno=r.nextRandom();

			t=buff[byteno] & 1;
				if(t==0)
					inputdata.putBitNo(bitno,0);
				
				else
						inputdata.putBitNo(bitno,1);
			bitno+=noofregions;
		//		bitno++;
		//		byteno++;
		}
		//byteno=0;
	/*	nextkey=key^prevkey;
		prevkey=key;
		key=nextkey;*/
	}

//	inputdata.flushbuff();

		
	

}

