#include <stdio.h>
#include <stdlib.h>
#include "integer.h"
#include "real.h"
#include "string.h"
#include "da.h"

void srandom(unsigned int);
long int random(void);

static void
display(DA *p,char *intro)
    {
    printf("%s",intro);
    if (sizeDA(p) < 200)
        {
        displayDA(p,stdout);
        }
    else
        {
        int k = 100;
        int j;
        printf("(displaying first and last %d elements)\n",k);
        for (j = 0; j < k; ++j)
            {
            displayINTEGER(getDA(p,j),stdout);
            printf(" ");
            }
        printf("... ");
        for (j = 0; j < k; ++j)
            {
            displayINTEGER(getDA(p,sizeDA(p)-k+j),stdout);
            if (j < k - 1) printf(" ");
            }
        printf("\n");
        }
    printf("\n");
    }

int
main(void)
    {
    srandom(1);
    printf("INTEGER test of DA, simple\n");
    int i;
    DA *p = newDA();
    setDAfree(p,freeINTEGER);
    setDAdisplay(p,displayINTEGER);
    debugDA(p,1);
    display(p,"items: ");
    for (i = 0; i < 2; ++i)
        {
        insertDA(p,0,newINTEGER(3));
        insertDA(p,1,newINTEGER(2));
        insertDA(p,0,newINTEGER(4));
        insertDA(p,sizeDA(p),newINTEGER(1));
        display(p,"items: ");
        freeINTEGER(removeDA(p,1));
        display(p,"items: ");
        freeINTEGER(removeDA(p,sizeDA(p)-1));
        display(p,"items: ");
        freeINTEGER(removeDA(p,0));
        display(p,"items: ");
        freeINTEGER(removeDA(p,0));
        display(p,"items: ");
        debugDA(p,0);
        }
    printf("size: %d\n",sizeDA(p));
    freeDA(p);
    return 0;
    }
