#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execl("/bin/grep", "grep", "main", "test.txt", NULL);  // grep "main" in test.txt
    } else if (pid > 0) {
        // Parent process
        printf("Parent process completed\n");
    } else {
        perror("Fork failed");
    }

    return 0;
}

