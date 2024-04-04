/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:13:14 by jfrances          #+#    #+#             */
/*   Updated: 2023/02/15 18:20:38 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long long n, char i)
{
	char	*digu;
	char	*digl;
	int		k;

	k = 0;
	digl = "0123456789abcdef";
	digu = "0123456789ABCDEF";
	if (n >= 16 && i == 'X')
	{	
		k += print_hex(n / 16, i);
		k += ft_putchar(digu[n % 16]);
	}
	else if (n >= 16 && i == 'x')
	{
		k += print_hex(n / 16, i);
		k += ft_putchar(digl[n % 16]);
	}
	else if (i == 'X' && n < 16)
		k += ft_putchar(digu[n % 16]);
	else if (i == 'x' && n < 16)
		k += ft_putchar(digl[n % 16]);
	return (k);
}
