#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>



int main() {
    int x = 100;
    int f = fork();
    if (f < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (f == 0) {
        //child
        printf("Childwert vor Zuweisung: %d\n", x);
        x = 69;
        printf("Childwert: %d\n", x);
    } else {
        // parent
        x = 420;
        printf("Parentwert: %d\n", x);
    }
    return 0;
}