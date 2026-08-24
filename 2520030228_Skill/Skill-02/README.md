# OSSP Skill-02: Keyboard Input & Buffer Management

## Aim
To write a C program that captures raw keyboard input, handles backspace deletion, processes the Enter key, and manages a multi-character input buffer.

## Key Implementation
* **Raw Mode:** Uses `termios` to disable canonical mode and read keystrokes immediately.
* **Backspace Handling:** Decrements buffer index and prints `\b \b` to erase characters from display.
* **Enter Key:** Appends `\0` null-terminator to convert buffer to string and submits command.
* **Buffer Limit:** Prevents buffer overflow by restricting input to `BUF_SIZE`.

## Commands Tested
* `status`
* `test command`
* `quit`

## Result
The custom input buffer managed backspaces, multi-character commands, and Enter key submissions correctly.

