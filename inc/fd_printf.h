#ifndef FD_PRINTF_H
# define FD_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

char		*fd_uitoa(unsigned int a);

int			fd_printf(int fd, const char *str, ...);
int			fd_putchar(int fd, int c);
int			fd_putchar_s(int fd, char *c);
int			fd_putchar_u(int fd, unsigned int a);
int			fd_putchar_d(int fd, int a);
int			fd_putchar_p(int fd, unsigned long long a);
void		fd_puthex(int fd, unsigned long long a);
int			fd_putchar_x(int fd, unsigned int a, int c);

#endif
