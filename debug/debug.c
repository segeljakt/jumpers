/******************************************************************************
*     File Name           :     debug.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-15 21:35]                            *
*     Last Modified       :     [AUTO_UPDATE_BEFORE_SAVE]                     *
*     Description         :     Debugging.                                    *
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
/*****************************************************************************/
static int lognumber = 0;
/*****************************************************************************/
void debug_log(char *text) {
    FILE *f = fopen("/Users/Klas/Git/my-projects/mario/debug/log.txt", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    if(lognumber == 0) {
        fprintf(f, "------------------------------------------------------\n");
    }
    /* print some text */
    fprintf(f, "%d: %s\n", lognumber, text);
    lognumber++;

    fclose(f);
}
