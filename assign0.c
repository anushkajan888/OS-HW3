#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());

    return 0;
}

