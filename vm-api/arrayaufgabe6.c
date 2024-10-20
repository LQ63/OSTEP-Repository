#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    int size = 100;
    int *data = malloc(size * sizeof(int));
    data[99] = 10;
    free(data + 50 * sizeof(int)); //incorrect, because
    printf("Value at data[99]: %d\n", data[99]);
}