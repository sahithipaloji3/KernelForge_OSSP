# OSSP Skill-01: Linux Command Execution & Hardware Abstraction

## Aim
To execute Linux commands using `fork()`, `execvp()`, and `wait()`, and analyze OS hardware abstractions.

## System Calls
* `fork()`: Creates a child process.
* `execvp()`: Replaces process memory with requested binary.
* `wait()`: Parent blocks until child finishes.
* `getpid()`, `getppid()`: Retrieve process identifiers.

## Hardware Resource Abstraction
* **CPU (`lscpu`):** Abstracted via time slicing, scheduling, and process states.
* **Memory (`top`):** Abstracted via Virtual Memory management and page tables.
* **Storage (`lsblk`):** Abstracted via Virtual File System (VFS) and block drivers.
* **Processes (`ps`):** Abstracted via Process Control Blocks (PCB).

## Result
Program executed commands via child process, synchronized with parent, and logged hardware metrics.
