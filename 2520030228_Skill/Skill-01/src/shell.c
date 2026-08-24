#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 1024

int main() {
    char input[MAX];
    char *args[64];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            continue;
        }

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        int i = 0;
        char *token = strtok(input, " \t");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \t");
        }
        args[i] = NULL;

        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("Command failed");
            }
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Fork failed");
        }
    }
    return 0;
}
