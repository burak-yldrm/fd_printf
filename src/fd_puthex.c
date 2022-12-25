#include "fd_printf.h"

void	fd_puthex(int fd, unsigned long long a)
{
	if (a >= 16)
	{
		fd_puthex(fd, a / 16);
		fd_puthex(fd, a % 16);
	}
	else
	{
		if (a <= 9)
			fd_putchar(fd, a + '0');
		else
			fd_putchar(fd, (a - 10) + 'a');
	}
}
