#include "fd_printf.h"

static int	fd_count(long a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a < 0)
		a = -a;
	while (a)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

int	fd_putchar_d(int fd, int a)
{
	int	len;

	len = fd_count(a);
	if (a == -2147483648)
	{
		len += fd_putchar(fd, '-');
		fd_putchar(fd, '2');
		a = 147483648;
	}
	if (a < 0)
	{
		a = a * -1;
		len += fd_putchar(fd, '-');
	}
	if (a < 10)
	{
		fd_putchar(fd, a + '0');
		return (len);
	}
	else
	{
		fd_putchar_d(fd, a / 10);
	}
	fd_putchar_d(fd, a % 10);
	return (len);
}
