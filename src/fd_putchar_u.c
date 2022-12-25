#include "fd_printf.h"

int	fd_putchar_u(int fd, unsigned int a)
{
	int		len;
	char	*num;

	len = 0;
	if (a == 0)
	{
		len += fd_putchar(fd, '0');
		return (len);
	}
	if ((int)a < 0)
	{
		if ((int)a == -1)
			a = 4294967295;
		else
			a = 4294967295 + a;
	}	
	num = fd_uitoa(a);
	len += fd_putchar_s(fd, num);
	free(num);
	return (len);
}
