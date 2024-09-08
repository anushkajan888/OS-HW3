#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execl("/bin/ls", "ls", NULL);  // Executes the 'ls' command
    } else if (pid > 0) {
        // Parent process
        printf("Parent process done\n");
    } else {
        perror("Fork failed");
    }

    return 0;
}

