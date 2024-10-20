#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int *i = malloc(sizeof(int));
    i = NULL;
    // printf("Value Pointer *i: %d\n", *i); probiere hier auf memory location zuzugreifen
    *i = 53; // modify the value but pointer doesn'T point somewhere
    free(i); // doesn't know what to free because i = NULL
}