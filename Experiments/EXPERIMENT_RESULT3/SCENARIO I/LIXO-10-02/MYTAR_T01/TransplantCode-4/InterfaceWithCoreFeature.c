
#include "archiver.h"

#include "InterfaceHeader.h"
struct archive archive = {0};

void write_archive_GRAFT_INTERFACE (char *$_host_ec, char *$_host_s, char *$_host_path) {
    int $_main_argc;
    char **$_main_argv;
    struct archive *$_process_command_line_a1 = &archive;
    $_process_command_line_a1->append_files_count = 1;
    $_process_command_line_a1->command = COM_CREATE;
    $_process_command_line_a1->file_name = $_host_path;
    goto LABEL_process_command_line1;
LABEL_process_command_line1 :
    if (0) {
    }
    struct archive *$_open_archive_file_archive1 = &archive;
    int $ABSTRETVAL_ret_open_archive_file1;
    $_open_archive_file_archive1->fd = open ($_open_archive_file_archive1->file_name, $_open_archive_file_archive1->fmode, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    $ABSTRETVAL_ret_open_archive_file1 = $_open_archive_file_archive1->fd;
    goto LABEL_open_archive_file1;
LABEL_open_archive_file1 :
    if (0) {
    }
    $_host_ec = $_main_argv[$_main_argc - 1];
    struct archive *$_read_archive_header_archive1 = &archive;
    size_t $_read_archive_header_descriptors_size_1;
    $_read_archive_header_descriptors_size_1 = sizeof (struct descr) * $_read_archive_header_archive1->append_files_count;
    int $_read_archive_header_result_1;
    $_read_archive_header_result_1 = read ($_read_archive_header_archive1->fd, &$_read_archive_header_archive1->files_count, sizeof ($_read_archive_header_archive1->files_count));
    $_read_archive_header_descriptors_size_1 += sizeof (struct descr) * $_read_archive_header_archive1->files_count;
    $_read_archive_header_archive1->file_descriptors = malloc ($_read_archive_header_descriptors_size_1);
    $_read_archive_header_result_1 = lseek ($_read_archive_header_archive1->fd, -$_read_archive_header_archive1->headers_offset, SEEK_END);
    goto LABEL_read_archive_header1;
LABEL_read_archive_header1 :
    if (0) {
    }
    write_archive ($_host_ec, & archive);
}

