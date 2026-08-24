#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define BUF_SIZE 256

// Set terminal to raw mode to capture individual keystrokes
void set_raw_mode(struct termios *orig) {
    struct termios raw;
    tcgetattr(STDIN_FILENO, orig);
    raw = *orig;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void reset_terminal(struct termios *orig) {
    tcsetattr(STDIN_FILENO, TCSANOW, orig);
}

int main() {
    struct termios orig_termios;
    char buffer[BUF_SIZE];
    int pos = 0;
    char ch;

    printf("=== Custom Keyboard Input & Buffer Test ===\n");
    printf("Type commands (Backspace works, press Enter to submit, type 'quit' to exit):\n");
    printf("input> ");
    fflush(stdout);

    set_raw_mode(&orig_termios);

    while (1) {
        if (read(STDIN_FILENO, &ch, 1) == 1) {
            // Enter Key (\n or \r)
            if (ch == '\n' || ch == '\r') {
                buffer[pos] = '\0';
                reset_terminal(&orig_termios);
                printf("\n[Buffer Submitted]: %s\n", buffer);

                if (strcmp(buffer, "quit") == 0) {
                    printf("Exiting handler...\n");
                    break;
                }

                pos = 0;
                printf("input> ");
                fflush(stdout);
                set_raw_mode(&orig_termios);
            }
            // Backspace Key (ASCII 127 or \b)
            else if (ch == 127 || ch == '\b') {
                if (pos > 0) {
                    pos--;
                    // Erase character visually from terminal
                    printf("\b \b");
                    fflush(stdout);
                }
            }
            // Regular multi-character input
            else if (ch >= 32 && ch <= 126) {
                if (pos < BUF_SIZE - 1) {
                    buffer[pos++] = ch;
                    putchar(ch);
                    fflush(stdout);
                }
            }
        }
    }

    reset_terminal(&orig_termios);
    return 0;
}
