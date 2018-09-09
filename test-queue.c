#include <stdio.h>
#include <stdlib.h>
#include "integer.h"
#include "real.h"
#include "string.h"
#include "cda.h"
#include "queue.h"

void srandom(unsigned int);
long int random(void);

static void
display(QUEUE *p,char *intro)
    {
    printf("%s",intro);
    if (sizeQUEUE(p) < 200)
        {
        displayQUEUE(p,stdout);
        }
    else
        {
        printf("(displaying top element)\n");
        displayINTEGER(peekQUEUE(p),stdout);
        printf("\n");
        }
    printf("\n");
    }

int
main(void)
    {
    srandom(1);
    printf("INTEGER test of QUEUE, simple\n");
    int i;
    QUEUE *p = newQUEUE();
    setQUEUEfree(p,freeINTEGER);
    setQUEUEdisplay(p,displayINTEGER);
    display(p,"items: ");
    for (i = 0; i < 3; ++i)
        {
        enqueue(p,newINTEGER(3));
        enqueue(p,newINTEGER(2));
        enqueue(p,newINTEGER(4));
        enqueue(p,newINTEGER(1));
        debugQUEUE(p,i);
        display(p,"items: ");
        }
    debugQUEUE(p,0);
    freeINTEGER(dequeue(p));
    display(p,"items: ");
    freeINTEGER(dequeue(p));
    display(p,"items: ");
    freeINTEGER(dequeue(p));
    display(p,"items: ");
    freeINTEGER(dequeue(p));
    display(p,"items: ");
    printf("size: %d\n",sizeQUEUE(p));
    freeQUEUE(p);
    return 0;
    }
