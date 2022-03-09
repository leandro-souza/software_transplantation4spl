
#include "InterfaceHeader.h"
struct descr {
    char file_name [256];
    size_t data_length;
    size_t data_start;
} __attribute__ ((packed));
struct archive {
    enum commands command;
    char *file_name;
    int fmode;
    int fd;
    uint32_t files_count;
    size_t append_files_count;
    size_t headers_offset;
    struct descr *file_descriptors;
};
struct archive archive = {0};

void write_archive (char *in_file, struct archive *archive) {
    char *input_file = (char *) malloc (1000 * sizeof (char));
    strcpy (input_file, in_file);
    write_archive_data (input_file, archive);
    write_archive_header (archive);
}

int write_archive_data (char *input_file_name, struct archive *archive) {
    lseek (archive -> fd, archive -> headers_offset, SEEK_END);
    printf ("Archive %s: writing file %s\n", archive -> file_name, input_file_name);
    append_file (archive, input_file_name);
    return 0;
}

int append_file (struct archive *archive, char *file_name) {
    struct descr *new_descr = archive->file_descriptors + archive->files_count;
    if (archive->files_count) {
        struct descr *last_descr = new_descr - 1;
        new_descr->data_start = last_descr->data_start + last_descr->data_length;
    }
    else
        new_descr->data_start = 0;
    struct stat stat_data;
    if (-1 == stat (file_name, &stat_data)) {
        return 0;
    }
    new_descr->data_length = stat_data.st_size;
    int fd = open (file_name, O_RDONLY);
    if (-1 == fd) {
        return 0;
    }
    void *file_data = mmap (NULL, new_descr->data_length, PROT_READ, MAP_PRIVATE, fd, 0);
    if (MAP_FAILED == file_data) {
        close (fd);
        return 0;
    }
    check_io_errors (write (archive -> fd, file_data, new_descr -> data_length), "write()");
    munmap (file_data, new_descr -> data_length);
    close (fd);
    strncpy (new_descr -> file_name, file_name, 255);
    return ++archive->files_count;
}

int check_io_errors (int ret_code, const char *operation) {
    if (-1 == ret_code) {
        exit (- 1);
    }
    return ret_code;
}

int write_archive_header (struct archive *archive) {
    check_io_errors (write (archive -> fd, archive -> file_descriptors, archive -> files_count * sizeof (struct descr)), "write()");
    check_io_errors (write (archive -> fd, & archive -> files_count, sizeof (archive -> files_count)), "write()");
    return 0;
}

void GRAFT_INTERFACE (void *$_host_user_data, char *$_host_filename, char *$_host_outputFileName, gchar *$_host_dir, struct stat $_host_st, PurpleXferType $_host_type, PurpleXfer *$_host_xfer) {
    struct archive *$_process_command_line_a1 = &archive;
    int $_process_command_line_option_index_1;
    $_process_command_line_option_index_1 = 1;
    $_process_command_line_a1->command = COM_CREATE;
    $_process_command_line_a1->fmode = O_RDWR | O_CREAT | O_EXCL;
    $_process_command_line_a1->file_name = $_host_outputFileName;
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
    size_t $_read_archive_header_descriptors_size_1;
    $_read_archive_header_archive1->file_descriptors = malloc ($_read_archive_header_descriptors_size_1);
LABEL_read_archive_header1 :
    if (0) {
    }
    char *$_write_archive_in_file1 = $_host_filename;
    struct archive *$_write_archive_archive1 = &archive;
    return write_archive ($_write_archive_in_file1, $_write_archive_archive1);
}

