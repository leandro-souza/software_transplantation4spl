CFLAGS = -I ../Host/pidgin-2.10.9/libpurple/ -I/usr/include/glib-2.0 `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0`

CHECKPACKAGE = `pkg-config --cflags --libs check`

Individual.x:	main.o InterfaceWithCoreFeature.o
	gcc -std=gnu99 -o Individual.x main.o InterfaceWithCoreFeature.o -lm $(CHECKPACKAGE) $(CFLAGS)

main.o:	main.c
	gcc -std=gnu99 -c -o main.o main.c $(CFLAGS)

InterfaceWithCoreFeature.o:	InterfaceHeader.h InterfaceWithCoreFeature.c
	gcc -std=gnu99 -c -o InterfaceWithCoreFeature.o InterfaceWithCoreFeature.c $(CFLAGS)

