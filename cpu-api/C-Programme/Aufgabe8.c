#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>



int main() {

    int fds[2]; //Pipeeingang, Pipeausgang
    char buffer[50]; // Speicher in der Pipe

    if (pipe(fds) == -1) { // pipe(fds) erstellt die pipe
        perror("pipe");
        exit(1);
    }

    int f = fork();

    if (f < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (f == 0) {
        //child
        close(fds[0]); // Read Möglichkeit geschlossen
        dup2(fds[1], STDOUT_FILENO); //Verbinden von Output der Pipe zur Standardausgabe
        close(fds[1]);
        printf("Servus Child. Wie goats dir?"); // wird redirected in pipe
    } else {
        // parent
        int g = fork();
        if (g < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
        } else if (g == 0) {
            //gchild
            close(fds[1]);
            read(fds[0], buffer, sizeof(buffer)); // Daten aus dem Pipe in den Buffer lesen
            if (strcmp(buffer, "Servus Child. Wie goats dir?") == 0) {
                printf("%s\n", buffer);
                printf("Mir gehts gut!\n");
            } else {
                printf("Hat nicht funktioniert\n");
            }


        } else {
        // parent
        }
    }
    return 0;
}