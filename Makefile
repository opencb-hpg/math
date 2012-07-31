CC = gcc
CFLAGS = -static -std=c99 -O3 -Wall
CFLAGS_DEBUG = -static -std=c99 -g

LIBS_DIR = $(PWD)/..

INCLUDES = -I$(PWD) -I$(PWD)/algebra -I$(PWD)/data -I$(PWD)/stats
LIBS = -lgsl

OBJECTS = array_utils.o fitting.o math_utils.o p_adjust.o statistics.o stats_inference.o
#matrix.o R_utils.o


all: $(OBJECTS)

compile:
	$(CC) $(CFLAGS) -c *.c algebra/*.c data/*.c stats/*.c $(INCLUDES) $(LIBS)

array_utils.o:
	$(CC) $(CFLAGS) -c data/array_utils.c $(INCLUDES) $(LIBS)

fitting.o:
	$(CC) $(CFLAGS) -c algebra/fitting.c $(INCLUDES) $(LIBS)

fisher.o:
	$(CC) $(CFLAGS) -c stats/fischer.c $(INCLUDES) $(LIBS)

math_utils.o:
	$(CC) $(CFLAGS) -c math_utils.h $(INCLUDES) $(LIBS)

matrix.o:
	$(CC) $(CFLAGS) -c data/matrix.c $(INCLUDES) $(LIBS)

R_utils.o:
	$(CC) $(CFLAGS) -c data/R_utils.c $(INCLUDES) $(LIBS)

p_adjust.o:
	$(CC) $(CFLAGS) -c stats/p_adjust.c $(INCLUDES) $(LIBS)

statistics.o:
	$(CC) $(CFLAGS) -c stats/statistics.c $(INCLUDES) $(LIBS)

stats_inference.o:
	$(CC) $(CFLAGS) -c stats/stats_inference.c $(INCLUDES) $(LIBS)

clean:
	rm -f *.o
