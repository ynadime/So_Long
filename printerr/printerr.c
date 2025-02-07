
#include "printerr.h"

static int	check_format(va_list args, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_errputchar(va_arg(args, int));
	else if (format == 's')
		count = ft_errputstr(va_arg(args, char *));
	else if (format == 'p')
	{
		count += ft_errputstr("0x");
		count += ft_errhexa(va_arg(args, unsigned long int), 'x');
	}
	else if (format == 'd' || format == 'i')
		count += ft_errputnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_errputunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_errhexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		count = ft_errputchar('%');
	return (count);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	printerr(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, str);
	if (write(2, 0, 0) == -1)
		return (-1);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			count += check_format(args, str[i + 1]);
			i += 2;
		}
		else
		{
			count += ft_errputchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
