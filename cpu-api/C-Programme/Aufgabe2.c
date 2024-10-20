#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>



int main() {
    int filedescriptor = open("testaufruf.txt", O_WRONLY | O_CREAT | O_TRUNC); //A file descriptor is an integer that uniquely identifies an open file within a process
    int f = fork();
    if (f < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (f == 0) {
        //child
        dprintf(filedescriptor, "Child: Irgendwas"); // fflush benutzen, damit direkt beschrieben
    } else {
        // parent
        //wait(NULL); // damit Child zuerst in .txt schreibt
        dprintf(filedescriptor, "Parent: Irgendwas"); // fflush benutzen, damit direkt beschrieben
    }
    return 0;
}