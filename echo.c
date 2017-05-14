#include <stdio.h>

int main(void)
{
  int c, e;

  while((c = getchar()) != EOF) {

    e = putchar(c);

    if (e == EOF) return 1;
  }

  return 0;
}
