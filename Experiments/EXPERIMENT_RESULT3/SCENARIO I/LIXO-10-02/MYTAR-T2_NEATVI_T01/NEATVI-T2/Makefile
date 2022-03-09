CC = cc
CFLAGS = -Wall -O2 -DVI_MAIN -DF_WRITE_ARCHIVE -DF_DIR_INIT -DF_DIR_INIT_TOO
LDFLAGS =

OBJS = vi.o ex.o InterfaceWithCoreFeature.o lbuf.o mot.o sbuf.o ren.o dir.o syn.o reg.o led.o \
	uc.o term.o rset.o regex.o cmd.o conf.o io.o \
	header.o append.o

all: vi

conf.o: conf.h

archiver.o: archiver.h

InterfaceHeader.o: InterfaceHeader.h

%.o: %.c
	$(CC) -c $(CFLAGS) $<
vi: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
clean:
	rm -f *.o vi
