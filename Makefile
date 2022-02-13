CC=gcc
CFLAGS=-Wall -ggdb -pedantic `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2` -lm

fractal: main.c linalg.c linalg.h
	$(CC) $(CFLAGS) -o fractal main.c linalg.c $(LIBS)