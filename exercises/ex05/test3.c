#include <stdio.h>
#include <stdlib.h>

#include "rand.h"

int main (int argc, char *argv[])
{
  int i;
  double x;

  srandom (time (NULL));

  for (i=0; i<10000; i++) {
    x = my_random_double();
    printf ("%g\n", x);
  }

  return 0;
}
