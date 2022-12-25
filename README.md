# FD_PRINTF
This project is a printf project that works with the file descriptor.

## How to use it
### Compilation

```bash
make or make all	--> compile the library
make exec			--> returns an executable file. To use it, first remove the main function in the fd_printf from the comment line.
make clean			--> clean the .o files
make fclean			--> clean the .o files and the executable file or the library
make re				--> recompile the library
```

### Usage

```c
#include "fd_printf.h"

int main(void)
{
	fd_printf(fd, "Hello World!\n");
	// fd is the file descriptor.
	// You can use 1 for stdout or 2 for stderr
	// or 0 for stdin or 3 and later for files.
	return (0);
}
```

## How it works
### Conversion

| Conversion | Description |
| :---: | :---: |
| c | print a character |
| s | print a string |
| p | print a pointer |
| d | print a decimal number |
| i | print a decimal number |
| u | print an unsigned decimal number |
| x | print a hexadecimal number in lowercase |
| X | print a hexadecimal number in uppercase |
| % | print a % |
