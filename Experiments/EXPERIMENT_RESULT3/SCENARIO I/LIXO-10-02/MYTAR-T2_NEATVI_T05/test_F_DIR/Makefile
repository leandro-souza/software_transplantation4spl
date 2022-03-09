CC = cc
CFLAGS =  -I/usr/include/glib-2.0 `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -Wall -g -DF_WRITE_ARCHIVE -DF_DIR_INIT -DF_DIR_INIT_TOO $(INCLUDE) 

CHECKPACKAGE = `pkg-config --cflags --libs check`
LDFLAGS =


OBJS = test_dir.o vi.o ex.o InterfaceWithCoreFeature.o lbuf.o mot.o sbuf.o ren.o dir.o syn.o reg.o led.o \
	uc.o term.o rset.o regex.o cmd.o conf.o io.o \
	header.o append.o

all: Individual.x

conf.o: conf.h

archiver.o: archiver.h

InterfaceHeader.o: InterfaceHeader.h

%.o:  %.c 
	$(CC) -c  $(CFLAGS)  $<
Individual.x: $(OBJS)
	$(CC) -o $@ $(OBJS) -lm $(CHECKPACKAGE) $(CFLAGS)

clean:
	rm -rf *.o Individual.x