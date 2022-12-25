#include "fd_printf.h"

static int	fd_count(unsigned int a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

static void	fd_uplow(int fd, unsigned int a, int c)
{
	if (c == 'X')
		fd_putchar(fd, (a - 10) + 'A');
	else
		fd_putchar(fd, (a - 10) + 'a');
}

int	fd_putchar_x(int fd, unsigned int a, int c)
{
	int	len;

	len = fd_count(a);
	if (a == 0)
	{
		write (fd, "0", 1);
		return (len + 1);
	}
	else
	{
		if (a >= 16)
		{
			fd_putchar_x(fd, (a / 16), c);
			fd_putchar_x(fd, (a % 16), c);
		}
		else
		{
			if (a <= 9)
				fd_putchar(fd, a + '0');
			else
				fd_uplow(fd, a, c);
		}
	}
	return (len);
}
