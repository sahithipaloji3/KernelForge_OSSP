# OSSP Skill-01: Simple Interactive Shell

## Aim
To write a basic interactive shell program in C that displays a prompt, takes user commands, executes them using child processes, and exits when typing `exit`.

## How It Works
* Prints `myshell> ` continuously inside a `while(1)` loop.
* Reads the keyboard input into a buffer using `fgets()`.
* Checks if the user typed `exit` to stop the loop.
* Uses `strtok()` to split arguments and executes them using `fork()` + `execvp()`.

## Commands Tested
* `pwd`
* `ls`
* `exit`

## Result
The custom shell executes commands interactively and terminates properly on `exit`.

