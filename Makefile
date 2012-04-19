
CC = gcc
CFLAGS = -static -std=c99 -O3


SRC_DIR = .

INCLUDES = -I $(SRC_DIR)

ROOT = ~/appl/bioinfo-c

LIBS = -Llibs/gsl -lgsl

objects = vector.o matrix.o stats.o math_utils.o R_utils.o

all: $(objects)

vector.o: vector.h vector.c
	$(CC) $(CFLAGS) -c vector.c $(INCLUDES) $(LIBS)

matrix.o: matrix.h matrix.c
	$(CC) $(CFLAGS) -c matrix.c $(INCLUDES) $(LIBS)

stats.o: stats.h stats.c
	$(CC) $(CFLAGS) -c stats.c $(INCLUDES) $(LIBS)


.PHONY : clean
clean:
	rm -f *.o *~
