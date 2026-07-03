# C-like Compiler

A simple compiler written in **pure C**, using **CMake** for the build system and **Nix** for the environment.

---

## Stack
- **Language**: C
- **Build System**: CMake
- **Environment**: Nix

---

## Current Features
- Takes a **file as input**.
- Only handles **arithmetic expressions**.
- Token generation (lexical analysis).
- AST (Abstract Syntax Tree) creation.
- Expression evaluation.

---
## To-Do
- [ ] Implement operator precedence in the AST.

---
## Custom Commands
   Command     | Description               |
 |-------------|---------------------------|
 | `proj_build` | Compiles the project.     |
 | `proj_test`  | Runs the tests.           |
 | `proj_run`   | Executes the compiler.    |
 | `proj_coverage` | Generate the coverage page of the project |