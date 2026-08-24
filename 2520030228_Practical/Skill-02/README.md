# OSSP Skill-02: File I/O System Calls & System Call Tracing

## Aim
To implement a file-copy utility using low-level I/O system calls (`open`, `read`, `write`, `close`) and trace execution with `strace`.

## System Calls Used
* `open()`: Requests the kernel for a file descriptor.
* `read()`: Reads data from kernel disk cache into user buffer.
* `write()`: Transfers data from user buffer to file.
* `close()`: Frees the file descriptor table entry.

## User Space vs Kernel Space Transition
1. User application prepares buffer and invokes `read()` / `write()`.
2. System call trap switches CPU from User Mode to Kernel Mode.
3. Kernel performs device I/O and populates buffer.
4. CPU switches back to User Mode with results.

## System Call Tracing Analysis (`strace`)
Key sequence observed:
`execve` -> `brk`/`mmap` -> `openat` -> `read` -> `write` -> `close`.

## Result
File copied successfully and verified through syscall tracing.
