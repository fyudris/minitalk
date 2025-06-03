# `Minitalk`

Okay, let's break down the important concepts for the `minitalk` project. This project is about creating a small data exchange program between two processes, a `client` and a `server`, using **UNIX signals** as the sole method of communication.

## Core Concepts of The Project

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
## Understanding UNIX Signals

#### What are they?
Unix signals are a limited form of inter-process communication (IPC) used in UNIX-like operating systems. Think of them as software interrupts. They notify a process that a specific event has occured. The communication is generally **asynchronous**.

#### How are they sent?
- `kill` **function**: The primary way your client wil sned signals to the server is using the `kill` system call.
	```
	int	kill(pid_t pid, int sig);
	```
	`pid`: This is the Process ID of the target process (in your case, the server's PID).
	`sig`: This is the signal number you want to send (e.g., `SIGUSR1` or `SIGUSR2` as specified in your project).
- Despite its name, `kill` doesn't always terminate a process. It sends a signal, and what happens next depends on how the target process is configured to *handle* that signal.

#### How are they received and handled?
A process can define a "handler" function that will be executed when a specific signal is received. The two main functions for this are `signal` and `sigaction`.

##### 1. `signal` function
```
void	(*signal(int sig, void (*func)(int)))(int);
```
- `sig`: The signal number to set a handler for
- `func`: A pointer to a function (the handler) that takes an integer (the signal number) as an argument and returns void. You can also pass predefined macros like `SIG_DFL` (default action) or `SIG_IGN` (ignore signal).

The behaviour of `signal` can vary across different UNIX systems (it's not fully portable). Historically, on some systems, after a signal handler was invoked, the signal disposition would reset to default. This meant you'd have to call `signal` again inside your handler to re-establish it if you wanted to catch the same signal again. This unreliability is one reason `sigaction` is prefered.


##### 2. `sigaction` function
```
int	sigaction(int sig, const struct sigaction *act, struct sigaction *oldact);
```
- `sig`: Signal number
- `act`: A pointer to a `struct sigaction` that specifies the new action for the signal `sig`
- `oldact`: If non-NULL, the previous action for `sig` is stored here.

The `struct sigaciton` is more complex and provides finer control:
```
struct	sigaction {
	void	(*sa_handler)(int);		// Signal handler (like with signal ())
	void	(*sa_sigaction)(int, siginfo_t *, void *);	// More advanced signal handler
	sigset_t	sa_mask;		// Set of signals to be blocked during handler execution
	int			sa_flags;	// Flags to modify behaviour (e.g., SA_RESTART, SA_SIGINFO)
	void		(*sa_restorer)(void); 	// Not for application use
}
```
- You'll primarily use `sa_handler` (or `sa_sigaction` if you need more info about the signal), `sa_mask`, `sa_flags`.
- `sa_mask`: This allows you to specify a set of signals that will be blocked (prevented from interrupting the current handler) while your signal handler is executing. This is useful for preventing race conditions.
- `sa_flags`: This can modify the behaviour of signal handling. For example, `SA_RESTART` can make certain system calls automatically restart if interrupted by this signal handler. `SA_SIGINFO` makes it use `sa_sigaction` instead of `sa_handler`, which provides more context about the signal.

##### Why is `sigaction` better that `signal`?
- **Portability and Reliability:** `sigaction` provides consistent, reliable semantics across different UNIX systems. The behaviour of `signal` can be inconsistent.
- **Control:** `sigaction` gives you much more control over the signal handling process:
  - You can specify a mask of signals to be blocked during the execution of the handler (`sa_mask`). This helps prevent the handler from being interrupted by other signals (or even the same signal if not desired), which can prevent race conditions.
  - The `sa_flag` field offers options like `SA_RESTART` (to automatically restart interrupted system calls) and `SA_SIGINFO` (to receive more detailed information about the signal, including sender PID, if you use the `sa_sigaction` handler).
- **Atomicity:** Setting the signal action with `sigaction` is an atomic operation.

For Minitalk, the ability to control `sa_mask` can be particularly important to ensure that your signal processing logic (e.g., recontructing bits into a byte) isn't mesed up by another incoming signal before you're ready.

## Explanation of Listed Functions

- `signal (int sig, void (*func) (int))`:
As described above, sets a disposition for a signal. Simpler but less reliable/portable than `sigaction`.

- `sigemptyset(siget_t *set)`:
	- Initializes the signal set pointed to by `set` to be empty (it excludes all defined signals).
	- You always use this before adding signals to a set with `sigaddset` or when you want a truly empty mask for `sigaction`'s `sa_mask`.
	- Code usage (server-side, setting up `sigaction`):
	```
	#include <signal.h>

	void	my_signal_handler (int signum)
	{
		// This is where the server would handle SIGUSR1 or SIGUSR2
		// For Minitalk, it might reconstruct a bit of a character.
		if (signum == SIGUSR1)
		{
			// Process bit 0
		}
		else if (signum == SIGUSR2)
		{
			// Process bit 1
		}
	}
	int main(void) {
    	struct sigaction sa;

    	// Initialize the signal set to empty [cite: 33]
		if (sigemptyset(&sa.sa_mask) == -1) {
			perror("sigemptyset failed");
			return 1;
		}
		// You could add signals to sa.sa_mask here if you wanted to block
		// them during the handler's execution. For example, to block SIGUSR2
		// while SIGUSR1_handler is running:
		// sigaddset(&sa.sa_mask, SIGUSR2); [cite: 33]

		sa.sa_handler = my_signal_handler;
		sa.sa_flags = 0; // Or SA_RESTART, SA_SIGINFO as needed

		// Register handler for SIGUSR1
		if (sigaction(SIGUSR1, &sa, NULL) == -1) { // [cite: 33]
			perror("sigaction for SIGUSR1 failed");
			return 1;
		}
		// Register handler for SIGUSR2 (can use the same handler or a different one)
		if (sigaction(SIGUSR2, &sa, NULL) == -1) {
			perror("sigaction for SIGUSR2 failed");
			return 1;
		}

		// ... server waits for signals ...
		printf("Server ready, PID: %d\n", getpid());
		while(1) {
			pause();
		}
	return 0;
	}
	```

- `sigaddset (sigset_t *set, int signo)`
  - Adds the signal `signo` to the signal set pointed to by `set`.
  - You use this to build up the `sa_mask` in your `struct sigaciton` to specify which signals should be blocked during a signal handler's execution.

- `sigaction(int sig, const struct sigaction *act, struct sigaction *oldact)`: As described above, allows examination and change of the action associated with a specific signal. Thi is the preferred method for handling signals.

- `kill(pid_t pid, int sig)`: As described above, sends the signal `sig` to the process with ID `pid`. This will be used by your client to send `SIGUSR` and `SIGUSR2` to the server.
  - Code usage (client-side example):
	```
	#include <signal.h>   // For kill() and signal macros
	#include <sys/types.h> // For pid_t

	int	main(int argc, char **argv)
	{
		pid_t	server_pidl
		// char *message_to_send; // This would be argv[2]

		if (argc != 3)
		{
			printf("Usage: ./client <server_pid> <message>\n");
			return (1);
		}
		server_pid = atoi(argv[1]);
		// message_to_send = argv[2];

		printf("Client: Sending SIGUSR1 to server PID %d\n", server_pid);

		// Example: Sending SIGUSR1
		if (kill(erver_pid, SIGUSR1) == -2)
		{
			perror("kill failed"); // Basic error handling
		}
		return (0);
	}
	```

- `getpid(void)`:
  - Returns the process ID (PID) of the calling process.
  - Your server ust call this at startup and print its PID o the client knows where to send signals.
  - Code usage (server-side example):
	```
	int	main(void)
	{
		pid_t	my_pid;

		mypid = getpid();
		printf("Server PID: %d\n", my_pid);

		// ... server continues to run, sets up signal handlers, etc. ...
		while (1)
		{
			pause(); // Wait for signals
		}
	}
	```

- `pause(void)`:
  - Suspends the calling process until a signal is caught (i.e., a signal whose action is to either terminate the process or call a signal handler function).
  - This is a simple way for the server to wait for signals from the client without busy-waiting (consuming CPU in a loop). When a signal arrives and its handler completes, `pause` will return.

- `sleep(unsignaed int seconds)`:
  - Suspends execution of the calling process for a specified number of `seconds` or until a signal is caucht that is not ignored.
  - While it can be used, in Minitalk, you'll likely want more immediate responsiveness. `pause` is often more appropriate for waiting for the next signal. `sleep` could be used if you need a deliberate, longer pause, but for bit-by-bit communication, it;s often too coarse.

- `usleep(useconds_t useconds)`:
  - Suspends execution of the calling process for `useconds` microseconds (millionths of a second) or until a signal is caught.
  - This provides finer-grained pauses than `sleep`. It can be useful for the client to insert a very short delay between sending signals if you find that sending them back-to-back is too fast for the server to process, or if you're trying to implement a simple synchronization without acknowledgment (though acknowledgements are better). The project notes that if displaying 100 characters thakes 1 second, the program is too slow, so excessive use of `usleep` should be avoided.

## Asynchronous vs. Synchronous Communication
#### Synchronous Communication
- In a synchronous model, the sender sends a message and then waits for a response (acknowledgement) from the receiver before sending the next message. Operations are performed in a sequence, and one completes before the next begins.
- It's like a phone call: you say somethign, wait for the other person to respond, then you speak again.

#### Asynchronous Communication:
- In an asynchronous model, the sender can send a message and continue with other operations without waiting for an immediate response from the receiver. The receiver processes the message when it can and may or may not send a response later.
- Signal are inherently asynchronous: the client sends a signal, and the operating system delivers it to the server. The client doesn't automatically block and wait for the server to process it unless the client explicitly codes itslef to wait (e.g., using `pause()` for a return signal).
- For Minital's mandatory part, the communication from client to server is primarily asynchronous. The client sends bits; the server receives them. The server is not required to send anything back in the mandatory part.

### `printf` vs. `write` in Signal Handlers
This is very important: **It is generally insafe to call `printf` (or many other standard I/O functions) from within a signal handler.**
- **Async-Signal Safety**: Functions that are safe to call from within a signal handler are called **async-signal-safe**. `printf` is *not* on this list.
- **Why `printf` is unsafe**:
  - **Non-Reentrancy**: `printf` uses internal buffers and static data structures. If a signal arrives while the main program is already in the middle of a `printf` call (or another non-reentrant function that `printf` might use internally, like `malloc`), and the signal handler then also call `printf`, these two calls can interfere with each other's internal state, leading to corrupted output, deadlocks, or crashes.
  - **Buffered I/O**: `printf` is usually buffered. If the handler is interrupted, the buffer might be in an inconsistent state.

- **Why `write` is (often) safer:**
  - The `write` system call (pecifically `write(2)`) *is* generally async-signal-safe.
  - It's a more direct system call and typically doesn't have the same complex buffering issues of reliance on internal static data that `printf` does, especially when writing to a file descriptor that isn't a buffered stream.
  - For Minitalk, if you need to print something from the server's signal handler (though typically the main logic of printing the full string happens *after* all bits are received, not directly in the bit-receiving handler), you would use `write` to a file descriptor (like `1` forstandard output). Even then, you have to be careful. The string you pass to `write` should be prepared, and you're often limited in what you can safely do.

## Recommendation for Minitalk:
In your signal handler, do the absolute minimum required. Typically, this involves:
1. Setting a flag or updating a shared (`volatile sig_atomic_t`) variable.
2. Re-registering the handler if using `signal` (though not strictly necesary with `sigaction` if `SA_RESETHAND` isn't set).
3. The main part of your program (outside the signal handler) would then check this flag/variable and perform the more complex processing (like assembling bits into bytes, bytes into a string, and then printing the full string using `write` or your `ft_printf`).

## Ping-Pong Method (Client Waits for Server Acknowledgement)
This is a method to achieve more **synchronous** and **reliable** communication, especially relevant for the bonus part where the server acknowledges messages. It helps prevent data loss or corruption, especially considering the warning that "Linux system does NOT queue signals when you already have pending signals of this type!".

#### How it works:
1. **Client sends data (e.g., a bit or a byte)**: The client sends a signal (or a sequence of signals representing a bit/byte) to the server.
2. **Client waits**: After sending, the client *waits* for an acknowledment signal from the server. It might use `pause()` to wait for this signal.
3. **Server processes data**: The server receives the signal(s), process the bit/byte.
4. **Server sends acknowledgment**: Once the server has successfully processed the data and is ready for more, it sends a specific signal (e.g., `SIGUSR1`) back to the client's PID (the client would need to send its PID to the server first, or the server could use information from `sigaction`'s `sa_sigaction` handler if `SA_SIGINFO` is used).
5. **Client receives acknowledment**: The client's `pause()` unblocks (or its signal handler for the acknowledgement signal is trigered). The client now knows the server received the last piece of data.
6. **Repeat**: The client can now safely send the next piece of data.

#### Benefits:
- **Reliability**: Greatly reduces the chances of the client overwhelming the server with signals, as the client only sends new data after the previous data is confirmed. This directly addresses the issue of non-queued signals.
- **Synchronization**: It provides a clear synchronization point between client and server.

#### Implementation Consideration:
- The client will need a signal handler to catch the acknowledgement from the server.
- The server will need to know the client's PID to send the acknowledgement. This might involve the client sending its PID as the very first part of the message, or if you use `sa_sigaction` with `SA_SIGINFO` in the server, the `siginfo_t` structure ofthen contains the sender's PID (`si_pid`).
- This method is crucial if you aim for part where server acknowledgement is required. For the mandatory part, it's not strictly required, but understanding it helps in designing robust signal communication. You might impement a simpler flow control where the client just `uslep`s for a tiny duration between sending bits, hoping the server keeps up, but this is less robust that acknowledgments.
