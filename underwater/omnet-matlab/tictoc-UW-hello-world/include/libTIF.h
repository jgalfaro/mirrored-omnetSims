/*
 * MATLAB Compiler: 4.14 (R2010b)
 * Date: Fri Sep 12 13:57:44 2014
 * Arguments: "-B" "macro_default" "-v" "-B" "csharedlib:libTIF" "-W"
 * "lib:libTIF" "-T" "link:lib" "-v" "absorption.m" "A.m" "demodulatePSK.m"
 * "modulatePSK.m" "PSKExample.m" "simulateChannel.m" "TreeNode.m"
 * "mylowpassfilter.m" 
 */

#ifndef __libTIF_h
#define __libTIF_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_libTIF
#define PUBLIC_libTIF_C_API __global
#else
#define PUBLIC_libTIF_C_API /* No import statement needed. */
#endif

#define LIB_libTIF_C_API PUBLIC_libTIF_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libTIF
#define PUBLIC_libTIF_C_API __declspec(dllexport)
#else
#define PUBLIC_libTIF_C_API __declspec(dllimport)
#endif

#define LIB_libTIF_C_API PUBLIC_libTIF_C_API


#else

#define LIB_libTIF_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libTIF_C_API 
#define LIB_libTIF_C_API /* No special import/export declaration */
#endif

extern LIB_libTIF_C_API 
bool MW_CALL_CONV libTIFInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libTIF_C_API 
bool MW_CALL_CONV libTIFInitialize(void);

extern LIB_libTIF_C_API 
void MW_CALL_CONV libTIFTerminate(void);



extern LIB_libTIF_C_API 
void MW_CALL_CONV libTIFPrintStackTrace(void);

extern LIB_libTIF_C_API 
bool MW_CALL_CONV mlxAbsorption(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libTIF_C_API 
bool MW_CALL_CONV mlxA(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libTIF_C_API 
bool MW_CALL_CONV mlxDemodulatePSK(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libTIF_C_API 
bool MW_CALL_CONV mlxModulatePSK(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libTIF_C_API 
bool MW_CALL_CONV mlxPSKExample(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libTIF_C_API 
bool MW_CALL_CONV mlxSimulateChannel(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                     *prhs[]);

extern LIB_libTIF_C_API 
bool MW_CALL_CONV mlxTreeNode(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libTIF_C_API 
bool MW_CALL_CONV mlxMylowpassfilter(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                     *prhs[]);

extern LIB_libTIF_C_API 
long MW_CALL_CONV libTIFGetMcrID();



extern LIB_libTIF_C_API bool MW_CALL_CONV mlfAbsorption(int nargout, mxArray** a, mxArray* f);

extern LIB_libTIF_C_API bool MW_CALL_CONV mlfA(int nargout, mxArray** L, mxArray* a, mxArray* k, mxArray* d);

extern LIB_libTIF_C_API bool MW_CALL_CONV mlfDemodulatePSK(int nargout, mxArray** rxPSK, mxArray* packetWaveform, mxArray* numberOfBytes, mxArray* fs, mxArray* fc, mxArray* symbolsPerSecond);

extern LIB_libTIF_C_API bool MW_CALL_CONV mlfModulatePSK(int nargout, mxArray** txPSK, mxArray** numberOfSamples, mxArray* byteStream, mxArray* fs, mxArray* fc, mxArray* symbolsPerSecond);

extern LIB_libTIF_C_API bool MW_CALL_CONV mlfPSKExample();

extern LIB_libTIF_C_API bool MW_CALL_CONV mlfSimulateChannel(int nargout, mxArray** samples, mxArray** nr, mxArray* signal, mxArray* fs, mxArray* sps, mxArray* d, mxArray* P);

extern LIB_libTIF_C_API bool MW_CALL_CONV mlfTreeNode(int nargout, mxArray** varargout, mxArray* varargin);

extern LIB_libTIF_C_API bool MW_CALL_CONV mlfMylowpassfilter(int nargout, mxArray** y, mxArray* x);

#ifdef __cplusplus
}
#endif
#endif
