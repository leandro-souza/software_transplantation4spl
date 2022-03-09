
#include "archiver.h"

#include "InterfaceHeader.h"
struct archive archive = {0};

void write_archive_GRAFT_INTERFACE (char *$_host_ec, char *$_host_s, char *$_host_path) {
    int $_main_argc;
    char **$_main_argv;
    struct archive *$_process_command_line_a1 = &archive;
    int $ABSTRETVAL_ret_process_command_line1;
    $_process_command_line_a1->file_name = $_host_path;
    $ABSTRETVAL_ret_process_command_line1 = 1;
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
    $_host_s = $_main_argv[$_main_argc - 1];
    struct archive *$_read_archive_header_archive1 = &archive;
    int $ABSTRETVAL_ret_read_archive_header1;
    int $_read_archive_header_result_1;
    $_read_archive_header_result_1 = read ($_read_archive_header_archive1->fd, $_read_archive_header_archive1->file_descriptors, $_read_archive_header_archive1->headers_offset - sizeof ($_read_archive_header_archive1->files_count));
    $ABSTRETVAL_ret_read_archive_header1 = $_read_archive_header_result_1;
    goto LABEL_read_archive_header1;
LABEL_read_archive_header1 :
    if (0) {
    }
    write_archive ($_host_s, & archive);
}

