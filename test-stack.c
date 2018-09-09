#include <stdio.h>
#include <stdlib.h>
#include "integer.h"
#include "real.h"
#include "stack.h"
#include "string.h"

int main(void) {
  STACK *list = newSTACK();
  setSTACKdisplay(list, displayINTEGER);
  setSTACKfree(list, freeINTEGER);

  int x;       // used in peeking
  INTEGER *i;  // used in poping
  int size;    // used in sizing

  // push into STACK ->
  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");
  push(list, newINTEGER(0));
  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");
  push(list, newINTEGER(1));
  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");
  push(list, newINTEGER(2));
  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");
  push(list, newINTEGER(3));
  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");
  push(list, newINTEGER(4));
  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");
  push(list, newINTEGER(5));
  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");

  size = sizeSTACK(list);
  printf("the size of list is: %d\n", size);

  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");

  printf("\n");
  printf("The value ");
  i = pop(list);  // remove from front
  displayINTEGER(i, stdout);
  printf(" was removed.\n");
  freeINTEGER(i);
  printf("\n");

  size = sizeSTACK(list);
  printf("the size of list1 is: %d\n", size);

  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");

  printf("\n");
  x = getINTEGER((INTEGER *)peekSTACK(list));
  printf("peek STACK (first value): %d\n", x);
  printf("\n");

  printf("The value ");
  i = pop(list);  // remove from front
  displayINTEGER(i, stdout);
  printf(" was removed.\n");
  freeINTEGER(i);
  printf("\n");

  size = sizeSTACK(list);
  printf("the size of list1 is: %d\n", size);

  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");

  printf("\n");
  x = getINTEGER((INTEGER *)peekSTACK(list));
  printf("peek STACK (first value): %d\n", x);

  printf("The value ");
  i = pop(list);  // remove from front
  displayINTEGER(i, stdout);
  printf(" was removed.\n");
  freeINTEGER(i);
  printf("\n");

  size = sizeSTACK(list);
  printf("the size of list1 is: %d\n", size);

  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");

  printf("\n");
  x = getINTEGER((INTEGER *)peekSTACK(list));
  printf("peek STACK (first value): %d\n", x);

  printf("The value ");
  i = pop(list);  // remove from front
  displayINTEGER(i, stdout);
  printf(" was removed.\n");
  freeINTEGER(i);
  printf("\n");

  size = sizeSTACK(list);
  printf("the size of list1 is: %d\n", size);

  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");

  printf("\n");
  x = getINTEGER((INTEGER *)peekSTACK(list));
  printf("peek STACK (first value): %d\n", x);

  printf("The value ");
  i = pop(list);  // remove from front
  displayINTEGER(i, stdout);
  printf(" was removed.\n");
  freeINTEGER(i);
  printf("\n");

  size = sizeSTACK(list);
  printf("the size of list1 is: %d\n", size);

  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");

  printf("\n");
  x = getINTEGER((INTEGER *)peekSTACK(list));
  printf("peek STACK (first value): %d\n", x);

  printf("The value ");
  i = pop(list);  // remove from front
  displayINTEGER(i, stdout);
  printf(" was removed.\n");
  freeINTEGER(i);
  printf("\n");

  size = sizeSTACK(list);
  printf("the size of list1 is: %d\n", size);

  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");

  push(list, newINTEGER(5));
  push(list, newINTEGER(4));
  push(list, newINTEGER(3));

  printf("\n");
  size = sizeSTACK(list);
  printf("the size of list is: %d\n", size);

  displaySTACK(list, stdout);
  printf("\n");
  
  printf("\n");

  printf("\n");
  freeSTACK(list);
  return 0;
}