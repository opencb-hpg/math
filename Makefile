CC = gcc
CFLAGS = -static -std=c99 -O3 -Wall
CFLAGS_DEBUG = -static -std=c99 -g

SRC_DIR = .
ROOT = ~/appl/bioinfo-c

INCLUDES = -I $(SRC_DIR) -I /usr/include/gsl
LIBS =  -L libs/gsl -lgsl

OBJECTS = array_utils.o ls_fit.o math_utils.o R_utils.o p_adjust.o
#matrix.o p_adjust.o R_utils.o statistics.o


all: $(OBJECTS)

array_utils.o: array_utils.h array_utils.c
	$(CC) $(CFLAGS) -c array_utils.c $(INCLUDES) $(LIBS)

ls_fit.o:
	$(CC) $(CFLAGS) -c ls_fit.c $(INCLUDES) $(LIBS)

math_utils.o:
	$(CC) $(CFLAGS) -c math_utils.h $(INCLUDES) $(LIBS)

matrix.o:
	$(CC) $(CFLAGS) -c matrix.c $(INCLUDES) $(LIBS)

stats.o:
	$(CC) $(CFLAGS) -c stats.c $(INCLUDES) $(LIBS)

R_utils.o: R_utils.h  R_utils.c
	$(CC) $(CFLAGS) -c R_utils.c $(INCLUDES) $(LIBS)

p_adjust.o: p_adjust.h  p_adjust.c
	$(CC) $(CFLAGS) -c p_adjust.c $(INCLUDES) $(LIBS)

clean:
	rm -f *.o
