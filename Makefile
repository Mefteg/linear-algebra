.PHONY: clean, libraries, mrproper

CC = g++
CFLAGS = -W -Wall

prefix = .
bindir = $(prefix)/bin
libdir = $(prefix)/lib
includedir = $(prefix)/include
srcdir = $(prefix)/src
tmpdir = $(prefix)/tmp

### COMPILATION ###

#-- MAIN

main: directories liblog.a liblinearalgebra.a main.o
	$(CC) $(tmpdir)/main.o -L$(libdir) -llog -llinearalgebra -o $(bindir)/main

main.o: 
	$(CC) -c $(srcdir)/main.cpp -I $(includedir) -o $(tmpdir)/main.o $(CFLAGS)

#-- LIBRARY LOG

liblog.a: log.o
	ar -q $(libdir)/liblog.a $(tmpdir)/log.o

log.o:
	$(CC) -c $(srcdir)/log.cpp -I $(includedir) -o $(tmpdir)/log.o $(CFLAGS)

#-- LIBRARY LINEAR ALGEBRA

liblinearalgebra.a: matrix.o matrixaugmented.o
	ar -q $(libdir)/liblinearalgebra.a $(tmpdir)/*.o

matrix.o:
	$(CC) -c $(srcdir)/matrix.cpp -I $(includedir) -o $(tmpdir)/matrix.o $(CFLAGS)

matrixaugmented.o:
	$(CC) -c $(srcdir)/matrixaugmented.cpp -I $(includedir) -o $(tmpdir)/matrixaugmented.o $(CFLAGS)

#-- DIRECTORIES
directories:
	mkdir -p bin lib test tmp

### PHONY ###

clean:
	rm -rf *.o

clean-libraries:
	rm -rf $(libdir)/*.a

mrproper: clean clean-libraries
	rm -rf $(bindir)/main