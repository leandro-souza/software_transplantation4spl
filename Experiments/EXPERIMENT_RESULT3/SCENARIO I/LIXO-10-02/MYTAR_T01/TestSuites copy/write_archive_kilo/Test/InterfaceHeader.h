
#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <stdint.h>

#include <getopt.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <errno.h>

#include <string.h>

#include <sys/mman.h>

#include <internal.h>

#include <dbus-maybe.h>

#include <ft.h>

#include <util.h>
enum commands {COM_UNKNOWN = 0, COM_APPEND, COM_LIST, COM_CREATE};
struct descr;
struct archive;
extern struct archive archive;
void write_archive (char * in_file, struct archive * archive);
int write_archive_data (char * input_file_name, struct archive * archive);
int append_file (struct archive * archive, char * file_name);
int check_io_errors (int ret_code, const char * operation);
int write_archive_header (struct archive * archive);
void GRAFT_INTERFACE (void * $_host_user_data, char * $_host_filename, char * $_host_outputFileName, gchar * $_host_dir, struct stat $_host_st, PurpleXferType $_host_type, PurpleXfer * $_host_xfer);
