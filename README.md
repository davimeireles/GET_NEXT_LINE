# Project: Get_Next_Line (GNL) - Reading Lines from File Descriptors

## Project Overview

The primary objective of Get_Next_Line was to develop a function that reads a line ending with a newline character from a file descriptor. This project deepened my understanding of static variables, file I/O operations, and memory management in C.

## Key Features

### Core Functionality

- Read a line from a given file descriptor
- Handle multiple file descriptors simultaneously
- Return the read line without the newline character
- Return NULL when reaching the end of file or on error
- Properly handle reading from files, standard input, or even network connections

### Bonus Features

- Use a single static variable
- Handle multiple file descriptors without losing the reading thread on each of them

## Technical Implementation

### Function Prototype

```c
char *get_next_line(int fd);
