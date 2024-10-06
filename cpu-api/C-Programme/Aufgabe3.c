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
        printf("hello\n");
    } else {
        // parent
        // wait(NULL); // damit Child zuerst in .txt schreibt
        sleep(1); //pausiert das Programm für 1 Sekunde, CPU wird nicht benutzt, dadurch kann etwas anderes laufen
        printf("goodbye\n");
    }
    return 0;
}