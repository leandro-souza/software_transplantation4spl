
#include "kilo.h"

#include "InterfaceHeader.h"

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <check.h>

#include <ctype.h>

#include <errno.h>

#include <fcntl.h>

#include <stdarg.h>

#include <string.h>

#include <sys/ioctl.h>

#include <termios.h>

#include <time.h>

#include <unistd.h>

int compare_two_binary_files (FILE *fp1, FILE *fp2) {
    char ch1, ch2;
    int flag = 0;
    while (((ch1 = fgetc (fp1)) != EOF) && ((ch2 = fgetc (fp2)) != EOF)) {
        if (ch1 == ch2) {
            flag = 1;
            continue;
        }
        else {
            fseek (fp1, - 1, SEEK_CUR);
            flag = 0;
            break;
        }
    }
    if ((fgetc (fp1) != EOF) || (fgetc (fp2) != EOF)) {
        flag = 0;
    }
    if (flag == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

START_TEST (test_1) {
    char ** params;
    E.numrows = 0;
    params = (char **) malloc (2 * sizeof(char *));
    params[0]  = (char *) malloc (500 * sizeof(char));
    params[1] = (char *) malloc (500 * sizeof(char));
    strcpy (params [0], "kilo");
    strcpy (params [1], "FILE.txt");
    editorOpen_GRAFT_INTERFACE (params, 2);
    printf("E.::%d\n", E.numrows);
   if (E.numrows == 0) {
        ck_abort ();
   }
}

END_TEST Suite *money_suite (void) {
    Suite *s = suite_create ("GenTransSuite");
    TCase *tc_core = tcase_create ("Core");
    tcase_add_test (tc_core, test_1);
    suite_add_tcase (s, tc_core);
    return s;
}

int main (int argc, char **argv) {
    int number_failed;
    Suite *s = money_suite ();
    SRunner *sr = srunner_create (s);
    srunner_run_all (sr, CK_SILENT);
    printf ("\n\n");
    srunner_print (sr, CK_NORMAL);
    number_failed = srunner_ntests_failed (sr);
    srunner_free (sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

