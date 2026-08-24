#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char cmd[100];
    printf("Enter Linux command: ");
    if (!fgets(cmd, sizeof(cmd), stdin)) return 0;
    cmd[strcspn(cmd, "\n")] = 0;

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("\n--- Child Process ---\nChild PID  : %d\nParent PID : %d\n", getpid(), getppid());
        char *args[] = {cmd, NULL};
        execvp(args[0], args);
        perror("Exec failed");
        exit(1);
    } else {
        printf("\n--- Parent Process ---\nParent PID : %d\nChild PID  : %d\n", getpid(), pid);
        wait(NULL);
        printf("\nChild process completed.\nParent process continues.\n");
    }
    return 0;
}
