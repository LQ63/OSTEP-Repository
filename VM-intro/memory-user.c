#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Falsche Eingabeparameter");
        return 1;
    }
    printf("PID-Number of this process: %d\n", getpid());
    int megabytes = atoi(argv[1]);
    size_t bytes = megabytes * 1024 * 1024;

    char *x = (char *) malloc(bytes);
    if (x == NULL)
    {
        perror("malloc didn't work");
        return 1;
    }
    while (1) {
        for (int i = 0; i < bytes; i++)
        {
            x[i] = 'T';

        }
    }

    free(x);






}