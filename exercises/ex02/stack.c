/* Example code for Think OS.
Copyright 2014 Allen Downey
License: GNU GPLv3
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}

// 1. Fill an array of size 5 with 42s, fill it with 0-4,
//    print it.
// 2. A warning that 'function returns address of local variable'.
//    The address of a variable that is now out of its local scope
//    was returned.
// 3. Prints 0-4. The array is edited in each function, ending with
//    values 0-4.
// 4. Prints two zeros and some weird numbers. Maybe now that the
//    variable is out of scope, that memory address points to a
//    random value?
