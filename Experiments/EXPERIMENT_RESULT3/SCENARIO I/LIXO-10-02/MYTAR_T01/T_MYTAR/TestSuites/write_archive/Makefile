
CC = cc
INCLUDE = -I/Users/leandrosouza/CLion_workspace/muScalpel_spl/cmake-build-debug/Transplant-PRODUCT_B/T_MYTAR/Donor/MYTAR

CFLAGS = -I/Users/leandrosouza/CLion_workspace/muScalpel_spl/cmake-build-debug/Transplant-PRODUCT_B/ProductBase/VI  -I/usr/include/glib-2.0 `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -Wall -g $(INCLUDE)

CHECKPACKAGE = `pkg-config --cflags --libs check`
LDFLAGS =

OBJS =  test_suite.o InterfaceWithCoreFeature.o

all: Individual.x

InterfaceHeader.o:  InterfaceHeader.h

%.o:  %.c 
	$(CC) -c  $(CFLAGS)  $<
Individual.x: $(OBJS)
	$(CC) -o $@ $(OBJS) -lm $(CHECKPACKAGE) $(CFLAGS)

clean:
	rm -rf *.o Individual.x