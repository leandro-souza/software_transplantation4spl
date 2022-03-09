#include "InterfaceHeader.h"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>

/*
 * 
 */


int compare_two_binary_files(FILE *fp1, FILE *fp2) {
    char ch1, ch2;
    int flag = 0;
    while (((ch1 = fgetc(fp1)) != EOF) &&((ch2 = fgetc(fp2)) != EOF)) {
        if (ch1 == ch2) {
            flag = 1;
            continue;
        }
        else {
            fseek(fp1, -1, SEEK_CUR);
            flag = 0;
            break;
        }
    }

    if ((fgetc(fp1) != EOF) || (fgetc(fp2) != EOF)) {
        flag = 0;
    }

    if (flag == 0) {
        return 1;
        //printf("Two files are not equal :  byte poistion at which two files differ is %d\n", ftell(fp1) + 1);

    } else {
        return 0;
        //printf("Two files are Equal\n ", ftell(fp1) + 1);
    }

}

/*
int main() {
    char * commandRemoveOldFile = "rm /home/alex/NetBeansProjects/TESTgOto/dist/Debug/GNU-Linux-x86/resultsFeatures.tar";
    system(commandRemoveOldFile);


    char **params;
    params = (char **) malloc(500 * sizeof (char *));
    for (int i = 0; i < 500; i++) {
        params[i] = (char *) malloc(500 * sizeof (char));
    }
    strcpy(params [1], "-c");
    strcpy(params [2], "-f");
    strcpy(params [3], "/home/alex/NetBeansProjects/TESTgOto/dist/Debug/GNU-Linux-x86/resultsFeatures.tar");
    strcpy(params [4], "/home/alex/NetBeansProjects/TESTgOto/dist/Debug/GNU-Linux-x86/File1.in");
    strcpy(params [5], "/home/alex/NetBeansProjects/TESTgOto/dist/Debug/GNU-Linux-x86/File2.in");
    int length = 6;
    int TRANSPLANT_RESULT;
    TRANSPLANT_RESULT = GRAFT_INTERFACE(length, params);


    FILE * resultedFile = fopen("/home/alex/NetBeansProjects/TESTgOto/dist/Debug/GNU-Linux-x86/resultsFeatures.tar", "r");
    FILE * oracleFile = fopen("/home/alex/NetBeansProjects/TESTgOto/dist/Debug/GNU-Linux-x86/results.tar", "r");


    char * commandCompareFiles = "cmp /home/alex/NetBeansProjects/TESTgOto/dist/Debug/GNU-Linux-x86/File1.in /home/alex/NetBeansProjects/TESTgOto/dist/Debug/GNU-Linux-x86/results.tar";

    
    if(compare_two_binary_files(resultedFile, oracleFile)){
        printf("NOT EQUAL!!");
        fflush(stdout);
    }
    
    
    
    FILE * fp;
    fp = popen(commandCompareFiles, "r");
    char * line = (char *) malloc(500 * sizeof (char));
    fgets(line, 1000, fp);

    int foundPercentage = 0;
    while (fgets(line, 1000, fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

 */



START_TEST(test_1) {


    char * commandRemoveOldFile = "rm RESULT_MYTAR.TAR";
    system(commandRemoveOldFile);
    int TRANSPLANT_RESULT;
    struct stat st;
    PurpleXferType type;
    GRAFT_INTERFACE (NULL, "FILE.in", "RESULT_MYTAR.TAR", NULL,  st, type, NULL);
    FILE * resultedFile = fopen("RESULT_MYTAR.TAR", "r");
    FILE * oracleFile = fopen("RESULT_MYTAR_ORIGINAL.TAR", "r");
    if (compare_two_binary_files(resultedFile, oracleFile)) {
                ck_abort();
    }
   
}

END_TEST

Suite *
money_suite(void) {
    Suite *s = suite_create("GenTransSuite");
    // Core test case 
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_1);
    suite_add_tcase(s, tc_core);
    return s;
}

int main(int argc, char** argv) {
    int number_failed;
    Suite *s = money_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_SILENT);


    printf("\n\n");

    srunner_print(sr, CK_NORMAL);



    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
    //  return (EXIT_SUCCESS);
}




/*
int main () {
   
    FILE *fin = fopen ("/home/alex/NetBeansProjects/HostExample/input.in", "r");
    FILE *fout = fopen ("output.out", "w");
    
    int *arrayC;
    int length;
    fscanf (fin, "%d", & length);
    arrayC = (int *) malloc ((length + 1) * sizeof (int));
    int i;
    for (i = 0; i < length; i++) {
        fscanf (fin, "%d", & arrayC [i]);
    }
    for (i = 0; i < length; i++) {
        fprintf (fout, "%d ", arrayC [i]);
    }
    
    
    
    //result: 45 39 -104 61 7 -44 42 -20 45 -85
    int length = 10;
    int myArray[10] = { 3, 45, 1, 67, 8, 98, 12, -12, -133, 0 };
    
    
    short *TRANSPLANT_RESULT;
    TRANSPLANT_RESULT = GRAFT_INTERFACE (length, myArray, NULL, NULL);
    return (EXIT_SUCCESS);
}
 */
