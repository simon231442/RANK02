/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelma <manuelma@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:11 by manuelmarti       #+#    #+#             */
/*   Updated: 2025/02/06 04:58:19 by manuelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

t_chars	*g_msg;

int	reset_or_increment_time(int reset_time)
{
	static int	time = 0;

	if (reset_time == 1)
		time = 0;
	else if (time < TIME_OUT_MS && reset_time == 2)
		time++;
	if (time < TIME_OUT_MS)
		return (0);
	else
		return (1);
}

void	print_and_free(int print)
{
	t_chars	*temp;

	temp = g_msg;
	if (print)
	{
		while (temp)
		{
			write(1, &temp->c, 1);
			temp = temp->next;
		}
		write(1, "\n", 1);
	}
	while (g_msg)
	{
		temp = g_msg;
		g_msg = g_msg->next;
		free(temp);
	}
}

int	add_char_to_msg(char c)
{
	t_chars	*temp_msg;
	t_chars	*new_char;

	new_char = malloc(sizeof(t_chars));
	if (!new_char)
	{
		ft_printf("Error\nmalloc failed !\n");
		return (1);
	}
	new_char->c = c;
	new_char->next = NULL;
	if (!g_msg)
	{
		g_msg = new_char;
		return (0);
	}
	temp_msg = g_msg;
	while (temp_msg->next)
		temp_msg = temp_msg->next;
	temp_msg->next = new_char;
	return (0);
}

void	handle_signal(int signal)
{
	static char	current_char = 0;
	static int	bit_index = 0;

	if (reset_or_increment_time(0))
	{
		current_char = 0;
		bit_index = 0;
	}
	reset_or_increment_time(1);
	if (signal == SIGUSR2)
		current_char |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		if (add_char_to_msg(current_char))
			ft_printf("Error:\nMissing char\n");
		if (!current_char)
			print_and_free(1);
		current_char = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %d\n", getpid());
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_msg = NULL;
	while (1)
	{
		usleep(1000);
		if (reset_or_increment_time(2) && g_msg)
		{
			ft_printf("\nError\nincomplete msg : ");
			print_and_free(1);
			write(1, "\n", 1);
		}
	}
	return (0);
}
