#include <stdio.h>

void print_size(char name[], size_t size)
{
    printf("%s\t%zu\n", name, size);
}


int main(int argc, char *argv[])
{
    print_size("char", sizeof(char));
    print_size("int", sizeof(int));
    print_size("long", sizeof(long));
    print_size("float", sizeof(float));
    print_size("double", sizeof(double));  
    print_size("int *", sizeof(int *));

    return 0;
}
