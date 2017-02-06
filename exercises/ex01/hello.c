#include <stdio.h>

int main() {
  int x = 5; // movl    $5, -4(%rbp)
  int y = x + 1;
  printf("%d\n", y); // just cares about y with optimization

  return 0;
}
