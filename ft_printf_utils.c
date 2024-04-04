/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:46:10 by jfrances          #+#    #+#             */
/*   Updated: 2023/02/15 18:12:17 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
		i++;
	}
	if (nb < 10)
	{
		nb += '0';
		write(1, &nb, 1);
		i++;
	}
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putunsign(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
	{
		n += '0';
		write(1, &n, 1);
		i++;
	}
	else
	{
		i += ft_putunsign (n / 10);
		i += ft_putunsign (n % 10);
	}
	return (i);
}

int	condition_check(void)
{
	write(1, "-2147483648", 11);
	return (11);
}
