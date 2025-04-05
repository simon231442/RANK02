/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:30:06 by srenaud           #+#    #+#             */
/*   Updated: 2025/04/05 11:46:59 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client	g_client;

int	char_send(void)
{
	int	bits;
	int	success;

	bits = 0;
	while (bits < 8)
	{
		if (g_client.msg[g_client.i] & 1 << bits)
			success = kill(g_client.pid, SIGUSR1);
		else
			success = kill(g_client.pid, SIGUSR2);
		if (success == -1)
		{
			ft_printf("operation failed\n");
			return (1);
		}
		usleep(TIME_PER_BIT);
		bits++;
	}
	return (0);
}

int	msg_send(void)
{
	g_client.i = 0;
	while (g_client.msg[g_client.i])
	{
		if (char_send())
			return (1);
		g_client.i++;
	}
	if (char_send())
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (ft_printf("usage : ./client <PID> <message>\n"));
	g_client.pid = ft_atoi(av[1]);
	g_client.msg = av[2];
	if (g_client.pid <= 0 || g_client.pid > 100000000)
		return (ft_printf("Invalid PID (valid range: [1 - ]100000000)\n"));
	if (msg_send())
		return (ft_printf("operation failed"));
	return (0);
}
