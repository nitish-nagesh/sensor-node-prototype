# invoke SourceDir generated makefile for rfExamples.pem3
rfExamples.pem3: .libraries,rfExamples.pem3
.libraries,rfExamples.pem3: package/cfg/rfExamples_pem3.xdl
	$(MAKE) -f C:\Users\ga73sut\workspace_v9\rfEasyLinkTx_CC1350_LAUNCHXL_TI/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\ga73sut\workspace_v9\rfEasyLinkTx_CC1350_LAUNCHXL_TI/src/makefile.libs clean

