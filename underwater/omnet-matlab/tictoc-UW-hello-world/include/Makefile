MODS=absorption.m A.m demodulatePSK.m modulatePSK.m PSKExample.m simulateChannel.m TreeNode.m mylowpassfilter.m

all: libTIF

libTIF:
	mcc -v -B csharedlib:libTIF -v $(MODS)
	cp libTIF.so ../lib/

clean:
	rm -f *~ *.so libTIF.c  libTIF.exports  libTIF.h mccExcludedFiles.log  readme.txt  
	rm -f ../lib/libTIF.so
