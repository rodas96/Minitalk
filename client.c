/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:48:52 by codespace         #+#    #+#             */
/*   Updated: 2023/12/08 17:16:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char(int pid, char c)
{
    int bit = 0;
    
    while (bit < 8)
    {
        int bit_mask = 1 << bit;
        int is_set = c & bit_mask;

        if (is_set)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(900);
        bit++;
    }
}

void signal_handler(int sig)
{
    (void)sig;
}


int main (int argc, char **argv)
{
    int pid;
    int i;

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
    i = 0;
    pid = ft_atoi(argv[1]);
    while (argv[2][i])
    {
        send_char(pid, argv[2][i]);
        i++;
    }
    return (0);
}