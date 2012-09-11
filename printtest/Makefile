CC=gcc

OS := $(shell uname -s)

ifeq ($(OS), SunOS)
    LDFLAGS=-lsocket -lnsl
    endif

all: printtest

printtest: printtest.o
    $(CC) printtest.o -o printtest

printtest.o: printtest.c
    $(CC) -c  printtest.c

clean:
        rm -rf *.o printtest
