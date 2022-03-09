.POSIX:
.SUFFIXES:

CFLAGS = -I/usr/include/glib-2.0 `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -Wall -g

all: mytar
mytar:	main.o append.o  io.o list.o config.o header.o   
	gcc -std=gnu99 -o mytar main.o append.o  io.o list.o config.o header.o  -lm $(CHECKPACKAGE) $(CFLAGS)

main.o: archiver.h main.c
	gcc -std=gnu99 -c -o main.o main.c $(CFLAGS)

append.o : archiver.h append.c
	gcc -std=gnu99 -c -o append.o  append.c $(CFLAGS)

io.o :	archiver.h io.c
	gcc -std=gnu99 -c -o io.o  io.c $(CFLAGS)

list.o :	archiver.h list.c
	gcc -std=gnu99 -c -o list.o  list.c $(CFLAGS)

config.o : archiver.h config.c
	gcc -std=gnu99 -c -o config.o  config.c $(CFLAGS)

header.o : archiver.h header.c
	gcc -std=gnu99 -c -o header.o  header.c $(CFLAGS)

clean:
	rm -f mytar

