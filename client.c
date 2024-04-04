/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:45:07 by jfrances          #+#    #+#             */
/*   Updated: 2023/03/14 16:43:37 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	transmit(int pid, char *str)
{
	unsigned int	i;
	int				mv;
	unsigned int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		mv = 0;
		while (mv < 8)
		{
			if ((str[i] >> mv) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			mv++;
			usleep(80);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int				serv_pid;

	if (argc == 3)
	{
		serv_pid = ft_atoi(argv[1]);
		if (serv_pid <= 0)
		{
			write(1, "Server PID must be an Unsigned Integer\n", 40);
			return (0);
		}
		transmit(serv_pid, argv[2]);
		transmit(serv_pid, "\n");
	}
	else
		write(1, "Client format should be <PID> <MESSAGE>.\n", 42);
	return (0);
}
