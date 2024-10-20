#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    int *i = (int *) malloc(sizeof(int));
    *i = 12;
}