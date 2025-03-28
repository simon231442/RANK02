/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:30:06 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/28 14:07:47 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client	client;

int	char_send()
{
	int	bits;
	int	success;

	bits = 0;
	success = 1;
	while (bits < 8)
	{
		if (client.msg[client.i] & 1 << bits)
			success = kill(client.pid, SIGUSR1);
		else
			success = kill(client.pid, SIGUSR2);
		if (!success)
			return (1);
		usleep(TIME_PER_BIT);
		bits++;
	}
	return (0);
}

int	msg_send()
{
	client.i = 0;
	while (client.msg[client.i])
	{
		if (!char_send())
			return (1);
		client.i++;
	}
	if (!char_send())
		return (1);
	return (0);
}

int	main(int ac, char **av)
{	
	if (ac != 3)
		return (ft_printf("usage : ./client <PID> <message>\n"));
	if (ac == 3)
	{
		client.pid = ft_atoi(av[1]);
		client.msg = av[2];
		if (client.pid <= 0)
			return (ft_printf("PID can't be negative\n"));
		if (!msg_send())
			return (ft_printf("operation failed"));
	}
	return (0);
}