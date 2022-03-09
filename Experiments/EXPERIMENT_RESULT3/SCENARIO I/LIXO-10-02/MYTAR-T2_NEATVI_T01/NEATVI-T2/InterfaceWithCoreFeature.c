
#include "archiver.h"

#include "InterfaceHeader.h"
struct archive archive = {0};

void write_archive_GRAFT_INTERFACE (char *$_host_ec, char *$_host_s, char *$_host_path) {
    struct archive *$_process_command_line_a1 = &archive;
    $_process_command_line_a1->append_files_count = 1;
    $_process_command_line_a1->fmode = O_RDWR | O_CREAT | O_EXCL;
    $_process_command_line_a1->file_name = $_host_path;
    goto LABEL_process_command_line1;
LABEL_process_command_line1 :
    if (0) {
    }
    struct archive *$_open_archive_file_archive1 = &archive;
    $_open_archive_file_archive1->fd = open ($_open_archive_file_archive1->file_name, $_open_archive_file_archive1->fmode, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    goto LABEL_open_archive_file1;
LABEL_open_archive_file1 :
    if (0) {
    }
    struct archive *$_read_archive_header_archive1 = &archive;
    int $ABSTRETVAL_ret_read_archive_header1;
    size_t $_read_archive_header_descriptors_size_1;
    $_read_archive_header_descriptors_size_1 = sizeof (struct descr) * $_read_archive_header_archive1->append_files_count;
    int $_read_archive_header_result_1;
    if (COM_APPEND == $_read_archive_header_archive1->command || COM_LIST == $_read_archive_header_archive1->command) {
        $_read_archive_header_archive1->headers_offset += sizeof ($_read_archive_header_archive1->files_count);
        $_read_archive_header_descriptors_size_1 += sizeof (struct descr) * $_read_archive_header_archive1->files_count;
    }
    $_read_archive_header_archive1->file_descriptors = malloc ($_read_archive_header_descriptors_size_1);
    if (COM_APPEND == $_read_archive_header_archive1->command || COM_LIST == $_read_archive_header_archive1->command) {
    }
    $ABSTRETVAL_ret_read_archive_header1 = $_read_archive_header_result_1;
    goto LABEL_read_archive_header1;
LABEL_read_archive_header1 :
    if (0) {
    }
    write_archive ($_host_s, & archive);
}

