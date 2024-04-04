/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:23:24 by jfrances          #+#    #+#             */
/*   Updated: 2023/03/14 16:43:52 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	read_data(int signal)
{
	static int				len = 0;
	static char	bit = 0;

	len++;
	bit = bit >> 1;
	if (signal == SIGUSR2)
		bit = bit | 128;
	if (len == 8)
	{
		write(1, &bit, 1);
		len = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID is %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, read_data);
		signal(SIGUSR2, read_data);
		pause();
	}
	return (0);
}
