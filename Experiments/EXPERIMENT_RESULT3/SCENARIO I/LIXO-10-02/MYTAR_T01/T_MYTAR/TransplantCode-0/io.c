
#include "archiver.h"

int check_io_errors (int ret_code, const char *operation) {
    if (-1 == ret_code) {
        exit (- 1);
    }
    return ret_code;
}

