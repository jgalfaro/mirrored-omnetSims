/*
 * MATLAB Compiler: 4.14 (R2010b)
 * Date: Fri Sep 12 13:57:44 2014
 * Arguments: "-B" "macro_default" "-v" "-B" "csharedlib:libTIF" "-W"
 * "lib:libTIF" "-T" "link:lib" "-v" "absorption.m" "A.m" "demodulatePSK.m"
 * "modulatePSK.m" "PSKExample.m" "simulateChannel.m" "TreeNode.m"
 * "mylowpassfilter.m" 
 */

#include <stdio.h>
#define EXPORTING_libTIF 1
#include "libTIF.h"

static HMCRINSTANCE _mcr_inst = NULL;


#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libTIF_C_API
#define LIB_libTIF_C_API /* No special import/export declaration */
#endif

LIB_libTIF_C_API 
bool MW_CALL_CONV libTIFInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream((void *)(libTIFInitializeWithHandlers), 
                                    17134027);
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream, 
                                                                17134027);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_libTIF_C_API 
bool MW_CALL_CONV libTIFInitialize(void)
{
  return libTIFInitializeWithHandlers(mclDefaultErrorHandler, mclDefaultPrintHandler);
}

LIB_libTIF_C_API 
void MW_CALL_CONV libTIFTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_libTIF_C_API 
long MW_CALL_CONV libTIFGetMcrID() 
{
  return mclGetID(_mcr_inst);
}

LIB_libTIF_C_API 
void MW_CALL_CONV libTIFPrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_libTIF_C_API 
bool MW_CALL_CONV mlxAbsorption(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "absorption", nlhs, plhs, nrhs, prhs);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlxA(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "A", nlhs, plhs, nrhs, prhs);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlxDemodulatePSK(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "demodulatePSK", nlhs, plhs, nrhs, prhs);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlxModulatePSK(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "modulatePSK", nlhs, plhs, nrhs, prhs);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlxPSKExample(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "PSKExample", nlhs, plhs, nrhs, prhs);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlxSimulateChannel(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "simulateChannel", nlhs, plhs, nrhs, prhs);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlxTreeNode(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "TreeNode", nlhs, plhs, nrhs, prhs);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlxMylowpassfilter(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "mylowpassfilter", nlhs, plhs, nrhs, prhs);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlfAbsorption(int nargout, mxArray** a, mxArray* f)
{
  return mclMlfFeval(_mcr_inst, "absorption", nargout, 1, 1, a, f);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlfA(int nargout, mxArray** L, mxArray* a, mxArray* k, mxArray* d)
{
  return mclMlfFeval(_mcr_inst, "A", nargout, 1, 3, L, a, k, d);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlfDemodulatePSK(int nargout, mxArray** rxPSK, mxArray* packetWaveform, 
                                   mxArray* numberOfBytes, mxArray* fs, mxArray* fc, 
                                   mxArray* symbolsPerSecond)
{
  return mclMlfFeval(_mcr_inst, "demodulatePSK", nargout, 1, 5, rxPSK, packetWaveform, numberOfBytes, fs, fc, symbolsPerSecond);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlfModulatePSK(int nargout, mxArray** txPSK, mxArray** numberOfSamples, 
                                 mxArray* byteStream, mxArray* fs, mxArray* fc, mxArray* 
                                 symbolsPerSecond)
{
  return mclMlfFeval(_mcr_inst, "modulatePSK", nargout, 2, 4, txPSK, numberOfSamples, byteStream, fs, fc, symbolsPerSecond);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlfPSKExample()
{
  return mclMlfFeval(_mcr_inst, "PSKExample", 0, 0, 0);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlfSimulateChannel(int nargout, mxArray** samples, mxArray** nr, 
                                     mxArray* signal, mxArray* fs, mxArray* sps, mxArray* 
                                     d, mxArray* P)
{
  return mclMlfFeval(_mcr_inst, "simulateChannel", nargout, 2, 5, samples, nr, signal, fs, sps, d, P);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlfTreeNode(int nargout, mxArray** varargout, mxArray* varargin)
{
  return mclMlfFeval(_mcr_inst, "TreeNode", nargout, -1, -1, varargout, varargin);
}

LIB_libTIF_C_API 
bool MW_CALL_CONV mlfMylowpassfilter(int nargout, mxArray** y, mxArray* x)
{
  return mclMlfFeval(_mcr_inst, "mylowpassfilter", nargout, 1, 1, y, x);
}
