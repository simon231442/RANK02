/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelma <manuelma@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:09:00 by manuelmarti       #+#    #+#             */
/*   Updated: 2025/02/06 04:59:31 by manuelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

int	print_error(char *str)
{
	ft_printf(str);
	return (1);
}

void	send_char(char letter, pid_t pid)
{
	int	char_index;
	int	operation_succes;

	char_index = 0;
	while (char_index < 8)
	{
		operation_succes = 0;
		if (letter & (0x01 << char_index))
			operation_succes = kill(pid, SIGUSR2);
		else
			operation_succes = kill(pid, SIGUSR1);
		if (operation_succes)
			exit(print_error("Error\nIn 'kill()' function !\n"));
		char_index++;
		usleep(TIME_PER_BIT_US);
	}
}

void	send_msg(pid_t pid, char *msg)
{
	int	char_index;
	int	msg_len;

	char_index = 0;
	msg_len = ft_strlen(msg);
	while (char_index < msg_len)
		send_char(msg[char_index++], pid);
	send_char('\0', pid);
}

int	check_pid_is_num(char *pid)
{
	while (pid++)
		if (!ft_isdigit(*pid))
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*msg;

	if (ac == 3)
	{
		if (!check_pid_is_num(av[1]))
			return (print_error("Error:\nFirst argument is not a numeric\n"));
		pid = ft_atoi(av[1]);
		if (av[1][0] == '-')
			return (print_error("Error:\nPID cannot be negative\n"));
		if (pid <= 1 || pid > PID_MAX)
		{
			ft_printf("Error:\nPID is not valid (> 0 && < %d)\n", PID_MAX + 1);
			return (1);
		}
		if (!ft_strlen(av[1]))
			return (print_error("Error:\nEmpty message (second arg empty)\n"));
		msg = av[2];
		send_msg(pid, msg);
		return (0);
	}
	else
		return (print_error("Error:\nThe client needs PID + msg\n"));
}
