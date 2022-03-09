
#include "InterfaceHeader.h"
struct archive archive = {0};

void write_archive_GRAFT_INTERFACE (char * $_host_argv [], int $_host_argc, char * $_host_outputFileName, char * $_host_filename){
    struct archive *$_process_command_line_a1 = &archive;
        $_process_command_line_a1->command = COM_CREATE;
        $_process_command_line_a1->fmode = O_RDWR | O_CREAT | O_EXCL;
        $_process_command_line_a1->file_name = $_host_outputFileName;
        $_host_argc = 1;
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
        switch (archive.command) {
        case COM_CREATE :
            {
                struct archive *$_read_archive_header_archive1 = &archive;
                size_t $_read_archive_header_descriptors_size_1;
                $_read_archive_header_descriptors_size_1 = sizeof (struct descr) * $_read_archive_header_archive1->append_files_count;
                if (COM_APPEND == $_read_archive_header_archive1->command || COM_LIST == $_read_archive_header_archive1->command) {
                    $_read_archive_header_descriptors_size_1 += sizeof (struct descr) * $_read_archive_header_archive1->files_count;
                }
                $_read_archive_header_archive1->file_descriptors = malloc ($_read_archive_header_descriptors_size_1);
                if (COM_APPEND == $_read_archive_header_archive1->command || COM_LIST == $_read_archive_header_archive1->command) {
                }
                $_host_argc = $_host_argc;
                goto LABEL_read_archive_header1;
            LABEL_read_archive_header1 :
                if (0) {
                }
                write_archive ($_host_filename, & archive);
            }
            struct archive *$_read_archive_header_archive2 = &archive;
            size_t $_read_archive_header_descriptors_size_2;
            $_read_archive_header_descriptors_size_2 = sizeof (struct descr) * $_read_archive_header_archive2->append_files_count;
            $_host_argc = lseek ($_read_archive_header_archive2->fd, - sizeof ($_read_archive_header_archive2->files_count), SEEK_END);
            $_read_archive_header_descriptors_size_2 += sizeof (struct descr) * $_read_archive_header_archive2->files_count;
            $_read_archive_header_archive2->file_descriptors = malloc ($_read_archive_header_descriptors_size_2);
            $_host_argc = lseek ($_read_archive_header_archive2->fd, -$_read_archive_header_archive2->headers_offset, SEEK_END);
            $_host_argc = read ($_read_archive_header_archive2->fd, $_read_archive_header_archive2->file_descriptors, $_read_archive_header_archive2->headers_offset - sizeof ($_read_archive_header_archive2->files_count));
            $_host_argc = $_host_argc;
        LABEL_read_archive_header2 :
            if (0) {
            }
            list_archive_content (& archive);
        }
        cleanup (& archive);
}

