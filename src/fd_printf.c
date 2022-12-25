#include "fd_printf.h"

int	fd_putchar(int fd, int c)
{
	return (write(fd, &c, 1));
}

static int	fd_form(int fd, va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += fd_putchar(fd, va_arg(arg, int));
	else if (c == 's')
		len += fd_putchar_s(fd, va_arg(arg, char *));
	else if (c == 'p')
		len += fd_putchar_p(fd, va_arg(arg, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += fd_putchar_d(fd, va_arg(arg, int));
	else if (c == 'u')
		len += fd_putchar_u(fd, va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		len += fd_putchar_x(fd, va_arg(arg, unsigned int), c);
	else if (c == '%')
		len += fd_putchar(fd, '%');
	else
		len += fd_putchar(fd, c);
	return (len);
}

int	fd_printf(int fd, const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += fd_form(fd, arg, str[i++]);
		}
		else
			len += fd_putchar(fd, str[i++]);
	}
	va_end(arg);
	return (len);
}

// Sample main function to test fd_printf
// int	main(void)
// {
// 	fd_printf(1, "Hello World\n");
// 	fd_printf(1, "Hello %s\n", "World");
// 	fd_printf(1, "Hello %d\n", 42);
// 	fd_printf(1, "Hello %u\n", 42);
// 	fd_printf(1, "Hello %x\n", 42);
// 	fd_printf(1, "Hello %X\n", 42);
// 	fd_printf(1, "Hello %p\n", &fd_printf);
// 	fd_printf(1, "Hello %c\n", 'c');
// 	fd_printf(1, "Hello %%\n");
// 	return (0);
// }
