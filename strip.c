#include <stdio.h>
#include <stdbool.h>


int main()
{
    int c, b;

    while((c = getchar()) != EOF) {

	if (c == ' ' && b == ' ')
	    continue;

	putchar(c);
	b = c;
    }

    return 0;
}
