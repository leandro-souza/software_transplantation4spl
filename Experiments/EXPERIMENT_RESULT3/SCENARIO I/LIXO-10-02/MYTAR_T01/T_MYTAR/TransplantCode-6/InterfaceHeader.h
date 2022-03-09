
#include <ctype.h>

#include <fcntl.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/stat.h>

#include <unistd.h>
extern enum commands;
struct descr;
struct archive;
extern struct archive archive;
extern void write_archive (char * in_file, struct archive * archive);
void write_archive_GRAFT_INTERFACE (char * $_host_ec, char * $_host_s, char * $_host_path);
