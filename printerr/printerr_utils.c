
#include "printerr.h"

int	ft_errputchar(char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_errputstr(char *s)
{
	int	count;

	if (!s)
		return (write(2, "(null)", 6));
	count = 0;
	while (s[count])
	{
		write(2, &s[count], 1);
		count++;
	}
	return (count);
}

int	ft_errputnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += write(2, "-2147483648", 11);
	else if (n < 0)
	{
		count += write(2, "-", 1);
		count += ft_errputnbr(-n);
	}
	else if (n > 9)
	{
		count += ft_errputnbr(n / 10);
		count += ft_errputchar(n % 10 + '0');
	}
	else
		count += ft_errputchar(n + '0');
	return (count);
}

int	ft_errputunbr(unsigned int n)
{
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_errputnbr(n / 10);
		count += ft_errputchar(n % 10 + '0');
	}
	else
		count += ft_errputchar(n + '0');
	return (count);
}

int	ft_errhexa(unsigned long int nb, char format)
{
	int		count;
	char	*str;

	count = 0;
	if (format == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (nb > 15)
	{
		count += ft_errhexa(nb / 16, format);
		count += ft_errputchar(str[nb % 16]);
	}
	else
		count += ft_errputchar(str[nb]);
	return (count);
}
