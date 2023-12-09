/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorais <rmorais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:48:52 by codespace         #+#    #+#             */
/*   Updated: 2023/12/09 16:27:31 by rmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;
	int	bit_mask;
	int	is_set;

	bit = 0;
	while (bit < 8)
	{
		bit_mask = 1 << bit;
		is_set = c & bit_mask;
		if (is_set)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(900);
		bit++;
	}
}

void	signal_handler(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Error: Wrong number of arguments.\n");
		return (1);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Error: PID must be a number.\n");
			return (1);
		}
		i++;
	}
	signal(SIGUSR1, signal_handler);
	i = -1;
	while (argv[2][++i])
		send_char(ft_atoi(argv[1]), argv[2][i]);
	send_char(ft_atoi(argv[1]), '\0');
	return (0);
}
