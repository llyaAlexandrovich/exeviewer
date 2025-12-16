BUILDDIR := ../../../build/



winexe : winexe winexefunctions winexe_struct_filler_functions



winexe : winexe.h winexe.c
	$(GCC) -c -o $(BUILDDIR)winexe.$(OBJECTEXT) winexe.c


winexefunctions : winexe_functions.h winexe_functions.c
	$(GCC) -c -o $(BUILDDIR)winexefunctions.$(OBJECTEXT) winexe_functions.c


winexe_struct_filler_functions : winexe_struct_filler_functions.h winexe_struct_filler_functions.c
	$(GCC) -c -o $(BUILDDIR)winexe_struct_filler_functions.$(OBJECTEXT) winexe_struct_filler_functions.c
