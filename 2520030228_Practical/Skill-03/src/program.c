#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("[Child] PID: %d, PPID: %d | State: RUNNING\n", getpid(), getppid());
        printf("[Child] Sleeping for 2 seconds (Entering WAITING state)...\n");
        sleep(2);
        printf("[Child] Woke up. Exiting (TERMINATED state).\n");
        exit(0);
    } else {
        printf("[Parent] PID: %d, Child PID: %d | State: RUNNING\n", getpid(), pid);
        printf("[Parent] Waiting for child...\n");
        wait(NULL);
        printf("[Parent] Child collected. Parent exiting.\n");
    }
    return 0;
}
