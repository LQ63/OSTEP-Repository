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

    /**
        if (execl("/bin/ls", "/bin/ls", (char *)NULL) == -1) {
            fprintf(stderr, "execl failed\n");
            exit(1);
        }
    **/

    /**
        char *envp[] = { "PATH=/usr/bin", NULL };
        if (execle("/bin/ls", "ls", (char *)NULL, envp) == -1) {
            fprintf(stderr, "execle failed\n");
            exit(1);
        }
    **/

    /**
        if (execlp("ls", "ls", (char *)NULL) == -1) {
            fprintf(stderr, "execlp failed\n");
            exit(1);
        }
    **/

    /**
        char *args[] = { "/bin/ls", (char *)NULL};
        if (execv(args[0], args) == -1) {
            fprintf(stderr, "execv failed\n");
            exit(1);
        }
    **/

    /**
        char *args[] = { "ls", (char *)NULL};
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "execvp failed\n");
            exit(1);
        }
    **/

        char *envp[] = { "PATH=/usr/bin", NULL };
        char *args[] = { "ls", (char *)NULL };
        if (execvpe(args[0], args, envp) == -1) {
            fprintf(stderr, "execvpe failed\n");
            exit(1);
        }


        printf("hello\n");
    } else {
        // parent
        // wait(NULL); // damit Child zuerst in .txt schreibt
        printf("goodbye\n");
    }
    return 0;
}