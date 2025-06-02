# `Minitalk`

Okay, let's break down the important concepts for the `minitalk` project. This project is about creating a small data exchange program between two processes, a `client` and a `server`, using **UNIX signals** as the sole method of communication.

## Core Concepts

### 1. Client-Server Model
- You are building two separate programs: `client` and `server`.
- The **server** starts first and prints its Process ID (PID). This PID is crucial for the client to know where to send signals.
- The **client** takes the server's PID and a string input. It's job is to send this string to the server.
- The server, upon receiving the string, must print it.

### 2. UNIX Signals
- This is the **heart of the project.** All communication *must* happen via UNIX signals.
- You are restricted to using only two signals: `SIGUSR1` and `SIGUSR2`.
- **What are signals?**
  - Signals are a form of inter-process communication (IPC) in UNIX-like systems. They are asynchronous notifications sent to a process to notify it of an event.
- **How can signals send data?**
  - Since you can only send `SIGUSR1` or `SIGUSR2`, you can't directly send the string data with a single signal. You'll need to devise a protocol.
  - For example, you could represent each bit of a character using one signal (e.g., `SIGUSR1` for a `0` bit and `SIGUSR2` for a `1` bit).
  - The client would send a sequence of signals for each character in the string, and the server would interpret this sequence back into characters.

### 3. Signal Handling
- The server needs to "catch" and interpret the signals sent by the client. This is done using functions like `signal` or `sigaction`.
- `sigemptyset` and `sigaddset` are used to manage signal sets, often in conjuction with `sigaction`.

### 4. Process Identification (PID)
- The server needs to display its PID so the client can target it. The `getpid()` function will be used for this.
- The client uses the `kill()` function to send signals to the server's PID.

### 5. Synchronization and State
- The server must be able to receive strings from multiple clients sequentially without restarting. This implies the server needs to reset its state after successfully receiving and priting a string.
- **Critical Hint**: Linux systems do *not* queue signals if there are pending signals of the same type. It means if the client sends signals too fast, or the server doesn't process them quickly enough, signals might be lost.
- You'll need to think about how to ensure reliable transmission (e.g., the server might need to signal back to the client that it's ready for the next bit/byte).
- The `pause()` function can be used to make a process wait for a signal.
- `sleep()` and `usleep()` can introduce delays, which might be useful for crude synchronization or testing, but efficient solution aim to avoid unnecessary fixed delays.

## Key Requirements & Constraints
- **Language:** C
- No memory leaks. All allocated memory must be freed.
- **Makefile rules:** `$(NAME)`, `all`, `clean`, `fclean`, `re`, and compilation flags `-Wall, -Wextra, -Werror`.
- **Allowed functions:** `write`, `signal`, `kill`, `getpid`, `malloc`, `free`, `pause`, `sleep`, `usleep`, `exit`, `sigemptyset`, `sigaddset`, `sigaction`, and your own `ft_printf`.
- **Global Variables:** Only one global variable is allowed per program (client and server), and its use must be justified.

---
## Where to start?

