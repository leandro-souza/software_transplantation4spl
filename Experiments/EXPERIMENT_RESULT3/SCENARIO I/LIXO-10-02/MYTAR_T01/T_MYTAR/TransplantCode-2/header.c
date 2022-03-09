
#include "archiver.h"

int write_archive_header (struct archive *archive) {
    check_io_errors (write (archive -> fd, archive -> file_descriptors, archive -> files_count * sizeof (struct descr)), "write()");
    check_io_errors (write (archive -> fd, & archive -> files_count, sizeof (archive -> files_count)), "write()");
    return 0;
}

