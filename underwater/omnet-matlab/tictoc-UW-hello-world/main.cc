#include <stdio.h>
#include <cownedobject.h>
#include <envirdefs.h>
#include <startup.h>
#include <ver.h>
#include "libTIF.h"

USING_NAMESPACE


//
// The main() function
//
ENVIR_API int main(int argc, char *argv[]) {
    cStaticFlag dummy;
	
    //printf(OMNETPP_PRODUCT " Discrete Event Simulation  (C) 1992-2008 Andras Varga, OpenSim Ltd.\n");
    //printf("Version: " OMNETPP_VERSION_STR ", build: " OMNETPP_BUILDID ", edition: " OMNETPP_EDITION "\n");
    //printf("See the license for distribution terms and warranty disclaimer\n");

    // Call MATLAB application initialization function.
    if (!mclInitializeApplication(NULL,0)){
        fprintf(stderr, "Could not initialize the MATLAB application.\n");
        exit(-1);
    }

    // Call the library initialization functions.
    if (!libTIFInitialize()){
        fprintf(stderr, "Could not initialize libchannel properly.\n");
        exit(-1);
    }
   
    setupUserInterface(argc, argv);

    // Call the library termination functions.
    libTIFTerminate();
    // Call MATLAB application termination function.
    mclTerminateApplication();

    printf("\nEnd.\n");

    return 0;
}
