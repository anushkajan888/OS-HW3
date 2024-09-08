#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid1 = fork();

    if (pid1 == 0) {
        // First child process
        execl("/bin/ls", "ls", NULL);  // Executes the 'ls' command
    } else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            // Second child process
            execl("/bin/date", "date", NULL);  // Executes the 'date' command
        } else if (pid2 > 0) {
            // Parent process
            printf("Parent process done\n");
        } else {
            perror("Second fork failed");
        }
    }

    return 0;
}

