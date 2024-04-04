/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:35:39 by jfrances          #+#    #+#             */
/*   Updated: 2023/03/14 16:42:36 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	token_check(char i, va_list ap)
{
	int	len;

	len = 0;
	if (i == '\0')
		return (-1);
	if (i == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (i == 'd' || i == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (i == 'u')
		len += ft_putunsign(va_arg(ap, unsigned int));
	else if (i == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (i == '%')
		len += ft_putchar('%');
	else if (i == 'X' || i == 'x')
		len += print_hex(va_arg(ap, unsigned int), i);
	else if (i == 'p')
	{
		len += ft_putstr("0x");
		len += print_hex(va_arg(ap, unsigned long long), 'x');
	}
	return (len);
}

int	ft_printf(const char *a, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, a);
	while (a[i])
	{
		if (a[i] == '%')
		{
			len += token_check(a[i + 1], ap);
			i++;
		}
		else
			len += ft_putchar(a[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
