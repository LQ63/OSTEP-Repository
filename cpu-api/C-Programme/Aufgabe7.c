#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>



int main() {
    int f = fork();
    if (f < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (f == 0) {
        //child
        close(STDOUT_FILENO); // Descriptor wird geschlossen
        printf("Hallo ich habe den Standard output geschlossen und will trotzdem reinschreiben\n"); //wird daher nicht geschrieben
    } else {
        // parent
        printf("Parenttext\n");
    }
    return 0;
}