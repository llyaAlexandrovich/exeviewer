BUILDDIR := ../../../build/



target : winexe fill determine

winexe : winexe.h winexe.c
	$(GCC) -c -o $(BUILDDIR)winexe.$(OBJECTEXT) winexe.c


fill : fill/fill.h fill/fill.c
	$(GCC) -c -o $(BUILDDIR)fill.$(OBJECTEXT) fill/fill.c


determine : determine/determine.h determine/determine.c
	$(GCC) -c -o $(BUILDDIR)determine.$(OBJECTEXT) determine/determine.c
