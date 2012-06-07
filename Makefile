CC = gcc
CFLAGS = -static -std=c99 -O3
CFLAGS_DEBUG = -static -std=c99 -g

LIBS_DIR = $(PWD)/..

INCLUDES = -I $(PWD)
LIBS = -lgsl

OBJECTS = array_utils.o fitting.o math_utils.o stats_inference.o
#matrix.o p_adjust.o R_utils.o statistics.o


all: $(OBJECTS)

compile:
	$(CC) $(CFLAGS) -c *.c $(INCLUDES) $(LIBS)

array_utils.o:
	$(CC) $(CFLAGS) -c array_utils.c $(INCLUDES) $(LIBS)

fitting.o:
	$(CC) $(CFLAGS) -c fitting.c $(INCLUDES) $(LIBS)

math_utils.o:
	$(CC) $(CFLAGS) -c math_utils.h $(INCLUDES) $(LIBS)

matrix.o:
	$(CC) $(CFLAGS) -c matrix.c $(INCLUDES) $(LIBS)

statistics.o:
	$(CC) $(CFLAGS) -c statistics.c $(INCLUDES) $(LIBS)

stats_inferenc.o:
	$(CC) $(CFLAGS) -c stats_inferenc.c $(INCLUDES) $(LIBS)

clean:
	rm -f *.o
