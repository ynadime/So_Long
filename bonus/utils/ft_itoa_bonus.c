/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:26:09 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/18 12:26:49 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static size_t	count_digits(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	fillstr(char *str, size_t sign, size_t digits, int n)
{
	str[digits + sign] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (digits > 0)
	{
		str[digits + sign - 1] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	sign;
	size_t	f;

	f = 0;
	sign = 0;
	if (n < 0)
	{
		sign++;
		if (n == -2147483648)
		{
			n++;
			f++;
		}
	}
	str = (char *)malloc((count_digits(n) + sign + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fillstr(str, sign, count_digits(n), n);
	if (f == 1)
		str[count_digits(n) + sign - 1]++;
	return (str);
}
