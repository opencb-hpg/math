CC = gcc
CFLAGS = -static -std=c99 -O3
CFLAGS_DEBUG = -static -std=c99 -g

SRC_DIR = .
ROOT = ~/appl/bioinfo-c

INCLUDES = -I $(SRC_DIR)
LIBS = -lgsl

OBJECTS = array_utils.o ls_fit.o math_utils.o 
#matrix.o p_adjust.o R_utils.o statistics.o


all: $(OBJECTS)

array_utils.o:
	$(CC) $(CFLAGS) -c array_utils.c $(INCLUDES) $(LIBS)

ls_fit.o:
	$(CC) $(CFLAGS) -c ls_fit.c $(INCLUDES) $(LIBS)

math_utils.o:
	$(CC) $(CFLAGS) -c math_utils.h $(INCLUDES) $(LIBS)

matrix.o:
	$(CC) $(CFLAGS) -c matrix.c $(INCLUDES) $(LIBS)

stats.o:
	$(CC) $(CFLAGS) -c stats.c$(INCLUDES) $(LIBS)

clean:
	rm -f *.o
