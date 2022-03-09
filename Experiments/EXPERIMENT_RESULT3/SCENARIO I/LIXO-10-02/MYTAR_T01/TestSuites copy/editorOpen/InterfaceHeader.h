#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
extern enum editorKey;
extern enum editorHighlight;
struct editorConfig;
typedef struct erow erow;
extern struct editorConfig E;
extern struct abuf;
void editorOpen_GRAFT_INTERFACE (char * $_host_argv [], int $_host_argc);
