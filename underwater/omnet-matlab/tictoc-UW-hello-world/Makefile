#
# OMNeT++/OMNEST Makefile for tictocUW
#
# This file was generated with the command:
# opp_makemake -f --deep -O out -I/usr/local/MATLAB/R2010b/extern/include -I/home/user/Desktop/omnetpp-4.2.2/src/common -I/home/user/Desktop/omnetpp-4.2.2/src/envir -I/home/user/Desktop/omnetpp-4.2.2/include/platdep -L/home/user/UWNet/tictocUW/lib/ -L/usr/local/MATLAB/R2010b/runtime/glnx86/ -L/usr/local/MATLAB/R2010b/bin/glnx86/ -lmat -lTIF -lmwmclmcrrt
#

# Name of target to be created (-o option)
TARGET = tictocUW$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I/usr/local/MATLAB/R2010b/extern/include \
    -I/home/user/Desktop/omnetpp-4.2.2/src/common \
    -I/home/user/Desktop/omnetpp-4.2.2/src/envir \
    -I/home/user/Desktop/omnetpp-4.2.2/include/platdep \
    -I. \
    -Iinclude \
    -Ilib

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -Llib/ -L/usr/local/MATLAB/R2010b/runtime/glnx86/ -L/usr/local/MATLAB/R2010b/bin/glnx86/  -lmat -lTIF -lmwmclmcrrt
LIBS += -Wl,-rpath,`abspath lib/` -Wl,-rpath,`abspath /usr/local/MATLAB/R2010b/runtime/glnx86/` -Wl,-rpath,`abspath /usr/local/MATLAB/R2010b/bin/glnx86/`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = $O/main.o $O/txc1.o

# Message files
MSGFILES =

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f tictocUW tictocUW.exe libtictocUW.so libtictocUW.a libtictocUW.dll libtictocUW.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f include/*_m.cc include/*_m.h
	-rm -f lib/*_m.cc lib/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc include/*.cc lib/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/main.o: main.cc \
  /home/user/Desktop/omnetpp-4.2.2/src/envir/startup.h \
  /usr/local/MATLAB/R2010b/extern/include/mclmcr.h \
  /usr/local/MATLAB/R2010b/extern/include/mat.h \
  /home/user/Desktop/omnetpp-4.2.2/include/platdep/platdefs.h \
  /usr/local/MATLAB/R2010b/extern/include/mclmcrrt.h \
  /usr/local/MATLAB/R2010b/extern/include/mclbase.h \
  include/libTIF.h \
  /home/user/Desktop/omnetpp-4.2.2/src/envir/envirdefs.h \
  /home/user/Desktop/omnetpp-4.2.2/src/common/ver.h \
  /usr/local/MATLAB/R2010b/extern/include/matrix.h \
  /usr/local/MATLAB/R2010b/extern/include/tmwtypes.h
$O/txc1.o: txc1.cc \
  /usr/local/MATLAB/R2010b/extern/include/mclmcr.h \
  /usr/local/MATLAB/R2010b/extern/include/mat.h \
  /usr/local/MATLAB/R2010b/extern/include/mclmcrrt.h \
  /usr/local/MATLAB/R2010b/extern/include/mclbase.h \
  include/libTIF.h \
  /usr/local/MATLAB/R2010b/extern/include/matrix.h \
  /usr/local/MATLAB/R2010b/extern/include/tmwtypes.h
