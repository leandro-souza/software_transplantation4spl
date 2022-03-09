
#include "archiver.h"

#include "InterfaceHeader.h"

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <check.h>
/*
int compare_two_binary_files (FILE *fp1, FILE *fp2) {
    char ch1, ch2;
    int flag = 0;
    int count = 0;
    while (((ch1 = fgetc (fp1)) != EOF) && ((ch2 = fgetc (fp2)) != EOF)) {
        if (ch1 != ch2) {
            fseek (fp1, - 1, SEEK_CUR);
            fseek (fp2, - 1, SEEK_CUR);
            flag = 1;
            break;
        }
        count++;
    }
    if (flag == 0) {
        return 1;
    }
    else {
        return 0;
    }
}*/
int compare_two_binary_files (FILE *fp1, FILE *fp2) {
    int ch1, ch2;
    
    if (fp2 == NULL) {
        exit(1);
    } else {
        ch1 = getc(fp1);
        ch2 = getc(fp2);

        while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)) {
            ch1 = getc(fp1);
            ch2 = getc(fp2);
        }
        fclose(fp1);
        fclose(fp2);
        
        if (ch1 == ch2)
            return 1;
        else if (ch1 != ch2)
            return 0;
  }
}

/*
START_TEST (test_1) {
    char * commandRemoveOldFile = "rm RESULT_MYTAR.TAR";
    system(commandRemoveOldFile);
    int write_archive_TRANSPLANT_RESULT;
    write_archive_GRAFT_INTERFACE (1,1,"RESULT_MYTAR.TAR","FILE.in");
    FILE * resultedFile = fopen("RESULT_MYTAR.TAR", "r");
    if (!resultedFile)
        ck_abort();

    fclose(resultedFile);
}*/

START_TEST (test_1) {
    char *commandRemoveOldFile = "rm RESULT_MYTAR.TAR";
    system (commandRemoveOldFile);
    int write_archive_TRANSPLANT_RESULT;
    write_archive_GRAFT_INTERFACE (1, NULL, "RESULT_MYTAR.TAR", "FILE.in", 0,1,1,1,1,1,1,1,NULL);
    FILE *resultedFile = fopen ("RESULT_MYTAR.TAR", "r");
    FILE *oracleFile = fopen ("RESULT_MYTAR_ORIGINAL.TAR", "r");
    if (!compare_two_binary_files (resultedFile, oracleFile)) {
        ck_abort ();
    }
    fclose(resultedFile);
    fclose(oracleFile);
}

Suite *money_suite (void) {
    Suite *s = suite_create ("GenTransSuite");
    TCase *tc_core = tcase_create ("Core");
    tcase_add_test (tc_core, test_1);
   // tcase_add_test (tc_core, test_2);
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

