CC = gcc
CFLAGS = -static -std=c99 -O3

SRC_DIR = .

INCLUDES = -I $(SRC_DIR)

ROOT = ~/appl/bioinfo-c
LIBS_ROOT = $(PWD)/libs

LIBS = -lgsl

# OBJECTS = vector.o matrix.o stats.o
OBJECTS = tests.o
# math_utils.o R_utils.o

all: $(OBJECTS)


vector.o:
	$(CC) $(CFLAGS) -c vector.c $(INCLUDES) $(LIBS)

matrix.o:
	$(CC) $(CFLAGS) -c matrix.c $(INCLUDES) $(LIBS)

stats.o:
	$(CC) $(CFLAGS) -c stats.c$(INCLUDES) $(LIBS)

tests.o:
	$(CC) $(CFLAGS) -c tests.c $(INCLUDES) $(LIBS)

.PHONY : clean
clean:
	rm -f *.o *~
