CFLAGS = -I/Users/leandrosouza/CLion_workspace/muScalpel_spl/cmake-build-debug/Transplant-mytar/Host/pidgin-2.10.9/libpurple -I/usr/include/glib-2.0 `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -Wall -g


CHECKPACKAGE = `pkg-config --cflags --libs check`

Individual.x:	main_organ.o InterfaceWithCoreFeature.o 
	gcc -std=gnu99 -o Individual.x main_organ.o InterfaceWithCoreFeature.o -lm $(CHECKPACKAGE) $(CFLAGS)

main_organ.o:	main_organ.c
	gcc -std=gnu99 -c -o main_organ.o main_organ.c $(CFLAGS)

InterfaceWithCoreFeature.o:	 InterfaceHeader.h InterfaceWithCoreFeature.c
	gcc -std=gnu99 -c -o InterfaceWithCoreFeature.o InterfaceWithCoreFeature.c $(CFLAGS)

clean:
	rm -rf *.o Individual.x
