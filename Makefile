export GCC := gcc -ggdb -m64 -std=c11 -Werror -Wall -Wpedantic -Wextra -O3 -static -fanalyzer
SUBDIRS := src/formats/win-exe/

ifeq ($(OS),Linux)
	export OBJECTEXT := o
	export EXECUTABLEEXT := elf
	export LIBEXT := so
endif

ifeq ($(OS),Windows_NT)
	export OBJECTEXT := obj
	export EXECUTABLEEXT := exe
	export LIBEXT := dll
endif






target : exeviewer execute file winexe main benchmark src/types.h
	$(GCC) -fuse-ld=lld -o bin/exeviewer.$(EXECUTABLEEXT) src/types.h build/winexe.$(OBJECTEXT) build/fill.$(OBJECTEXT) build/exeviewer.$(OBJECTEXT) \
	build/execute.$(OBJECTEXT) build/file.$(OBJECTEXT) build/main.$(OBJECTEXT) build/determine.$(OBJECTEXT) build/benchmark.$(OBJECTEXT)


winexe :
	$(MAKE) -C $(SUBDIRS)


main : src/main.C
	$(GCC) -c -o build/main.$(OBJECTEXT) src/main.c


exeviewer : src/exeviewer/exeviewer.h src/exeviewer/exeviewer.c
	$(GCC) -c -o build/exeviewer.$(OBJECTEXT) src/exeviewer/exeviewer.c


execute : src/execute/execute.h src/execute/execute.c
	$(GCC) -c -o build/execute.$(OBJECTEXT) src/execute/execute.c


file : src/file/fileread.h src/file/fileread.c
	$(GCC) -c -o build/file.$(OBJECTEXT) src/file/fileread.c


benchmark : src/benchmark/benchmark.h src/benchmark/benchmark.C
	$(GCC) -c -o build/benchmark.$(OBJECTEXT) src/benchmark/benchmark.C
