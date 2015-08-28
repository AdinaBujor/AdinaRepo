///
/// @file
/// @copyright All code copyright Movidius Ltd 2014, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     This file contains the source code of the SIPP pipeline
///            generated by the SIPP Graph Designer.
///
///
///  ************************ DO NOT EDIT, THIS IS A GENERATED FILE!!!! ************************
/// 

#include "sippTutA0Model.h"

#include <include/sippHwDefs.h>




//The full-frame buffers
UInt8      DDR_DATA SippTutA0Model_dmaIn0_buffer[512      * 512     * 1  ]ALIGNED(8);
UInt8      DDR_DATA SippTutA0Model_dmaOut0_buffer[512      * 512     * 1  ]ALIGNED(8);
	
///
void readSippTutA0ModelInput(SippTutA0Model *pPl)
{
   sippRdFileU8((UInt8*)SippTutA0Model_dmaIn0_buffer,512        * 512     * 1 * sizeof(UInt8),"../../../../../../resources/lena_512x512_luma.raw");
	
}

void writeSippTutA0ModelOutput(SippTutA0Model *pPl)
{
   sippWrFileU8((UInt8*)SippTutA0Model_dmaOut0_buffer,512        * 512     * 1 * sizeof(UInt8),"output.raw");

}
   
void buildSippTutA0Model(SippTutA0Model *pPl)
{
   // create new pipeline
   pPl->pl               = sippCreatePipeline(0, 7, SIPP_MBIN(mbinImgSipp));

   // create filters
   pPl->dmaIn0          =  sippCreateFilter(pPl->pl, 0x00,       512,    512,    N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
   pPl->dmaOut0         =  sippCreateFilter(pPl->pl, 0x00,       512,    512,    N_PL(1),  SZ(UInt8), SIPP_AUTO,          (FnSvuRun)SIPP_DMA_ID,        0);
	
   // link filters
   sippLinkFilter(pPl->dmaOut0,       pPl->dmaIn0,        1,1);
	
}

  
void configSippTutA0Model(SippTutA0Model *pPl)
{
   DmaParam            *dmaIn0Cfg          = (DmaParam         *)pPl->dmaIn0->params;
   DmaParam            *dmaOut0Cfg         = (DmaParam         *)pPl->dmaOut0->params;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // here go through all the filter instances and assign the value for all parameter
  // fields as defined in the filter property window
   dmaIn0Cfg->ddrAddr   = (UInt32)&SippTutA0Model_dmaIn0_buffer;
   dmaOut0Cfg->ddrAddr  = (UInt32)&SippTutA0Model_dmaOut0_buffer;
  
  
}
