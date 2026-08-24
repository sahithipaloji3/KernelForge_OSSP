# OSSP Skill-03: Process State Transitions

## Aim
To observe process creation, parent-child lifecycles, and state transitions using `ps`, `top`, and `/proc`.

## Process States Observed
* **Ready:** In memory, awaiting CPU execution.
* **Running (R):** Actively executing on CPU.
* **Waiting / Sleeping (S):** Blocked waiting for event/`sleep()`.
* **Terminated / Zombie (Z):** Finished execution, waiting for parent `wait()`.

## Inspection Tools
* `ps -o pid,ppid,stat,comm`: Displays process state codes.
* `/proc/[PID]/status`: Kernel status of process.

## Result
Program demonstrated process state transitions and synchronization lifecycles.
