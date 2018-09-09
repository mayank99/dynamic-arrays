#include <stdio.h>
#include <stdlib.h>
#include "integer.h"
#include "real.h"
#include "string.h"
#include "da.h"
#include "stack.h"

void srandom(unsigned int);
long int random(void);

static void
display(STACK *p,char *intro)
    {
    printf("%s",intro);
    if (sizeSTACK(p) < 200)
        {
        displaySTACK(p,stdout);
        }
    else
        {
        printf("(displaying top element)\n");
        displayINTEGER(peekSTACK(p),stdout);
        printf("\n");
        }
    printf("\n");
    }

int
main(void)
    {
    srandom(1);
    printf("INTEGER test of STACK, simple\n");
    int i;
    STACK *p = newSTACK();
    setSTACKfree(p,freeINTEGER);
    setSTACKdisplay(p,displayINTEGER);
    display(p,"items: ");
    for (i = 0; i < 3; ++i)
        {
        push(p,newINTEGER(3));
        push(p,newINTEGER(2));
        push(p,newINTEGER(4));
        push(p,newINTEGER(1));
        debugSTACK(p,i);
        display(p,"items: ");
        }
    debugSTACK(p,0);
    freeINTEGER(pop(p));
    display(p,"items: ");
    freeINTEGER(pop(p));
    display(p,"items: ");
    freeINTEGER(pop(p));
    display(p,"items: ");
    freeINTEGER(pop(p));
    display(p,"items: ");
    printf("size: %d\n",sizeSTACK(p));
    freeSTACK(p);
    return 0;
    }
