#include <stdio.h>

//assumes little endian
void print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1; i>=0; i--)
    {
        for (j=7; j>=0; j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
	printf(" ");
    }
    puts("");
}

int main(int argc, char *argv[])
{
    float x;

    x = 0.15625;

    print_bits(sizeof(x), &x);

    return 0;
}
