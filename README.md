# Simple Shell

## Table of Contents

1. [Introduction](#introduction)  
2. [Features](#features)  
3. [Installation](#installation)  
4. [Usage](#usage)  
5. [Examples](#examples)  
6. [Built-in Commands](#built-in-commands)  
7. [Allowed Functions and System Calls](#allowed-functions-and-system-calls)  
8. [Project Structure](#project-structure)  
9. [Requirements](#requirements)  
10. [Bugs](#bugs)  
11. [Authors](#authors)  
12. [License](#license)

---

## Introduction

This project is a custom implementation of a simple UNIX shell as part of the ALX Software Engineering Program. 
The shell provides a command-line interface between the user and the operating system, allowing execution of commands, both built-in and external.

---

## Features

- Display a prompt and wait for user input.
- Handle command execution with arguments.
- Support built-in commands: `exit`, `env`, `setenv`, `unsetenv`.
- Handle the `PATH` environment variable to locate executables.
- Implement command execution using `fork`, `execve`, and `wait`.
- Handle End Of File (EOF) condition (Ctrl+D).
- Handle interrupts (Ctrl+C) without exiting the shell.
- Support both interactive and non-interactive modes.

---

## Installation

To compile and run the shell:

```bash
git clone https://github.com/deantosh/simple_shell.git
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

---

## Usage

### Interactive Mode

Run the shell and type commands:

```bash
./hsh
$ ls -l
$ pwd
$ exit
```

### Non-Interactive Mode

Pass commands as input:

```bash
echo "ls -l" | ./hsh
```

---

## Examples

```bash
$ ./hsh
#cisfun$ echo "Hello, World!"
Hello, World!
#cisfun$ /bin/ls
file1.c  file2.c  hsh
#cisfun$ exit
```

---

## Built-in Commands

- `exit`: Exit the shell.
- `env`: Display the environment variables.
- `setenv`: Initialize a new environment variable or modify an existing one.
- `unsetenv`: Remove an environment variable.

---

## Allowed Functions and System Calls

- `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`, `fflush`, `fork`, `free`, `getcwd`, `getline`, 
  `getpid`, `isatty`, `kill`, `malloc`, `open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `stat`, `lstat`, 
  `fstat`, `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`

---

## Project Structure

- `AUTHORS`: List of contributors.
- `man_1_simple_shell`: Manual page for the shell.
- `shell.h`: Header file with function prototypes and macros.
- `main.c`: Entry point of the shell.
- `builtins.c`: Implementation of built-in commands.
- `execute.c`: Functions to execute commands.
- `utils.c`: Utility functions.
- `path.c`: Functions to handle PATH variable.

---

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on Ubuntu 20.04 LTS using `gcc` with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the Betty style guide.
- No memory leaks.

---

## Bugs

No known bugs at this time. Please report any issues.

---

## Authors

Deantosh Daiddoh - [Github](https://github.com/deantosh) / [X](https://x.com/daiddoh)
Lucky Archibong - [Github](https://github.com/luckys-lnz) / [X](https://x.com/)

---

## License

This project is licensed under the MIT License.