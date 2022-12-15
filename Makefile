#****************************************************************************
# File name:  Makefile
# Author:     Computer Science, Pacific University
# Date:       
# Class:      CS300
# Assignment: Rational
# Purpose:    Create the drivers to test the Rational module
#****************************************************************************/

CC = gcc
CFLAGS = -g -Wall
OBJECTS = bin/rationalDriver.o bin/rational.o

.PHONY: all clean valgrind tarball

all: bin/rationalDriver

bin/rationalDriver: ${OBJECTS}
	${CC} ${CFLAGS} -o bin/rationalDriver ${OBJECTS}
	
#bin/reduceRational: bin/reduceRational.o bin/rational.o
#	${CC} ${CFLAGS} -o bin/reduceRational ${OBJECTS}

bin/rationalDriver.o: src/rationalDriver.c include/rational.h
	${CC} ${CFLAGS} -o bin/rationalDriver.o -c src/rationalDriver.c
	
#bin/reduceRational.o: src/reduceRational.c include/rational.h
#	${CC} ${CFLAGS} -o bin/reduceRational.o -c src/reduceRational.c

bin/rational.o:  src/rational.c include/rational.h
	${CC} ${CFLAGS} -o bin/rational.o -c src/rational.c

clean:
	rm bin/rationalDriver  ${OBJECTS}

valgrind: bin/rationalDriver
	valgrind -v --leak-check=yes bin/rationalDriver
	
tarball: clean
	tar czf ../CS300Rational.tar.gz ../CS300Rational
