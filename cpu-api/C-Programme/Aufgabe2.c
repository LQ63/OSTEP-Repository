#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>



int main() {
    FILE *file = fopen("testaufruf.txt", "w");
    int f = fork();
    if (f < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (f == 0) {
        //child
        fprintf(file, "Child: Irgendwas");
    } else {
        // parent
        // wait(NULL); // damit Child zuerst in .txt schreibt
        fprintf(file, "Parent: Irgendwas");
    }
    return 0;
}