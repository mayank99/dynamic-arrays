/*
 * Integer tester, by John C. Lusth
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "integer.h"

int
main(int argc,char **argv)
    {
    if (argc != 1)
        {
        fprintf(stderr,"usage: %s\n",argv[0]);
        exit(1);
        }

    printf("integer tester, version 1\n");
    INTEGER *x = newINTEGER(2);
    printf("x is %d\n",getINTEGER(x));
    setINTEGER(x,3);
    printf("x is now ");
    displayINTEGER(x,stdout);
    printf("\n");
    printf("freeing the integer\n");
    freeINTEGER(x);

    return 0;
    }
