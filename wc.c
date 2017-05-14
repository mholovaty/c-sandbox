#include <stdio.h>
#include <stdbool.h>

static bool is_whitespace(int c)
{
    if ((c == '\t') ||
	(c == '\n') ||
	(c == ' '))
	return true;
    return false;
}

int main()
{
    int c, n;

    n = 0;

    while((c = getchar()) != EOF)
	if (is_whitespace(c))
	    n++;

    printf("%d\n", n);

    return 0;
}
