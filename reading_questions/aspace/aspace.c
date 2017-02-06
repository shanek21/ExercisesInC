/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void printAddress(int var) {
  printf("Address of var is %p\n", &var);
}

int main ()
{
    int l1 = 30;
    int l2 = 30;
    void *p1 = malloc(20);
    void *p2 = malloc(20);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of l1 is %p\n", &l1);
    printf ("Address of l2 is %p\n", &l2);
    printAddress(l1);
    printAddress(l2);
    printf ("Address of p1 is %p\n", p1);
    printf ("Address of p2 is %p\n", p2);
    
    return 0;
}
