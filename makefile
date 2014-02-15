CC = g++

UNAME := $(shell uname)

PROJ = nlconv

ifeq ($(UNAME), Darwin)
OUTDIR = bin/osx
endif
ifeq ($(UNAME), Linux)
OUTDIR = bin/linux
endif

SOURCEFILES =                           \
				src/main.cpp                    \
				src/factory.cpp                 \
				src/conversion.cpp              \
				src/converter_base.cpp          \
				src/converter_2dos.cpp          \
				src/converter_2nix.cpp          \
				src/converter_2mac.cpp          \
				src/converter_2fix.cpp

HEADERFILES =	inc/*.h

COMPILER_OPTS = 

nlconv: $(SOURCEFILES) $(HEADERFILES)


	@echo "** Compiling..."
	$(CC) -o $(OUTDIR)/$(PROJ) $(SOURCEFILES) $(COMPILER_OPTS);
	@echo "Done."