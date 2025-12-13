GCC := gcc -m64 -std=c11 -Werror -Wall -O3
SUBDIRS := src/formats/win-exe/ ./

ifeq ($(OS),Linux)
	OBJECTEXT := o
	EXECUTABLEEXT := elf
	LIBEXT := so
endif

ifeq ($(OS),Windows_NT)
	OBJECTEXT := obj
	EXECUTABLEEXT := exe
	LIBEXT := dll
endif



all : $(SUBDIRS)


$(SUBDIRS) : exeviewer.o execute.o file.o src/types.h src/main.c
	$(MAKE) -C $@
	$(GCC) -static -o bin/exeviewer.$(EXECUTABLEEXT) build/exeviewer.$(OBJECTEXT) build/execute.$(OBJECTEXT) build/file.$(OBJECTEXT) src/types.h src/main.c


exeviewer.o : src/exeviewer/exeviewer.h src/exeviewer/exeviewer.c
	$(GCC) -c -o build/exeviewer.$(OBJECTEXT) src/exeviewer/exeviewer.c


execute.o : src/execute/execute.h src/execute/execute.c
	$(GCC) -c -o build/execute.$(OBJECTEXT) src/execute/execute.c


file.o : src/file/fileread.h src/file/fileread.c
	$(GCC) -c -o build/file.$(OBJECTEXT) src/file/fileread.c



.PHONY : all $(SUBDIRS)
