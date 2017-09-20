#include <stdio.h>

int main()
{
    int c, b = '\n';

    while((c = getchar()) != EOF) {
	if ((c != ' ') ||
	    ((b != ' ') && (b != '\n')))
	    putchar(c);

	b = c;
    }

    return 0;
}
