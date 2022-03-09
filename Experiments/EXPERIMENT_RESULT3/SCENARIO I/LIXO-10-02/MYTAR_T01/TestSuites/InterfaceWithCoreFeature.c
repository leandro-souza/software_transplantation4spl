
#include "InterfaceHeader.h"
#include "archiver.h"
#include <string.h>
struct archive archive = {0};
void write_archive_GRAFT_INTERFACE (char *$_host_ec, char *$_host_s, char *$_host_path) {
	//__INTERFACE_FUNCTION
    char *input_file = (char *) malloc (1000 * sizeof (char));
    strcpy(input_file,$_host_s);
   // strcpy(input_file, "FILE.in");
    archive.file_name = input_file;
}

