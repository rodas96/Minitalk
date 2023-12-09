/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorais <rmorais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:51:12 by rmorais           #+#    #+#             */
/*   Updated: 2023/12/09 16:25:11 by rmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#define MAX_STRING_LENGTH 1000000

char	*g_buffer;

void	ft_handle(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;
	static int	index;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		g_buffer[index] = c;
		if (c == '\0' || index == MAX_STRING_LENGTH - 1)
		{
			g_buffer[index] = '\0';
			ft_printf("%s\n", g_buffer);
			index = 0;
			ft_memset(g_buffer, 0, MAX_STRING_LENGTH);
		}
		else
			index++;
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	ft_exit(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)sig;
	free(g_buffer);
	exit(0);
}

void	init_struct(struct sigaction *sa, struct sigaction *sigint)
{
	sa->sa_sigaction = ft_handle;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = SA_SIGINFO;
	sigint->sa_sigaction = ft_exit;
	sigemptyset(&sigint->sa_mask);
	sigint->sa_flags = SA_SIGINFO;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	struct sigaction	sigint;

	g_buffer = malloc(MAX_STRING_LENGTH * sizeof(char));
	(void)argv;
	if (g_buffer == NULL)
		return (1);
	if (argc != 1)
	{
		ft_printf("Error: Wrong number of arguments.\n");
		free(g_buffer);
		return (1);
	}
	ft_printf("PID: %d\n", getpid());
	init_struct(&sa, &sigint);
	if (sigaction(SIGUSR1, &sa, NULL) != 0 
		|| sigaction(SIGUSR2, &sa, NULL) != 0 
		|| sigaction(SIGINT, &sigint, NULL) != 0)
	{
		free(g_buffer);
		return (1);
	}
	while (1)
		pause();
}
