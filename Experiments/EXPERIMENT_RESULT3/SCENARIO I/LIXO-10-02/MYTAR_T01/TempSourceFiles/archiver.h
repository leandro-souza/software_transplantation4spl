enum commands {COM_UNKNOWN = 0, COM_APPEND, COM_LIST, COM_CREATE};
struct descr {
    char file_name [256];
    size_t data_length;
    size_t data_start;
} __attribute__ ((packed));
