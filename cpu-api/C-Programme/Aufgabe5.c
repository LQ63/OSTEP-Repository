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
        int rc_wait = wait(NULL); // gibt -1 zurück, da es keine Child prozesse gibt, auf die er warten muss bzw. wegen error
        printf("hello, Rückgabewert wait(NULL) in child: %d\n", rc_wait);
    } else {
        // parent
        int rc_wait = wait(NULL); // damit Child zuerst in .txt schreibt

        printf("goodbye, Rückgabewert wait(NULL) in parent: %d\n", rc_wait); //bei Erfolg gibt wait(NULL) die PID des Child Prozesses zurück
    }
    return 0;
}