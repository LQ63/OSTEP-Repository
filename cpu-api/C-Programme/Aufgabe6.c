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
        int status; //store the dead child's status
        int rc_wait = waitpid(f, &status, 0);
        printf("hello, Rückgabewert waitpid() in child: %d\n", rc_wait); //waitpid returns -1, weil keine existing child prozesse
        printf ("Child Process terminated with status %d\n", status); // status = 0
    } else { //f ist hier die PID vom Child Prozess
        // parent
        int status; //store the dead child's status
        int rc_wait = waitpid(f, &status, 0); // damit Child zuerst, wartet bis GENAU dieser Child prozess fertig ist

        printf("goodbye, Rückgabewert waitpid() in parent: %d\n", rc_wait); //bei Erfolg gibt waitpid() die PID des Child Prozesses zurück
        printf ("Child Process terminated with status %d\n", status); //if status = 0, it exited normally
    }
    return 0;
}