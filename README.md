# minishell_project

## Description
This project is a simple shell implementation in C, inspired by bash. It supports command execution, environment variables, built-in commands, piping, and redirections.

## Features
- Command parsing and execution
- Built-in commands: `cd`, `echo`, `pwd`, `export`, `unset`, `exit`
- Environment variable management
- Input/output redirection
- Piping between commands
- Signal handling (Ctrl+C, Ctrl+\, etc.)
- Custom error handling

## Project Structure
- `src/` — Source code for the shell and its components
- `include/` — Header files
- `lib/` — External libraries (libft)
- `Makefile` — Build instructions

## How to Build
```sh
make
```

## How to Run
```sh
./minishell
```

## Authors
- Your Name <your.email@example.com>

## License
This project is for educational purposes.