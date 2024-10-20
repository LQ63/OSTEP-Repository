#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    int size = 100;
    int *data = malloc(size * sizeof(int));
    data[99] = 0; // warum geht bei data[100]

}