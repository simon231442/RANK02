/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:34 by srenaud           #+#    #+#             */
/*   Updated: 2025/04/01 15:05:34 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server;

static int	mt_char_add(void);
static int	mt_buff_expand(void);
static void	mt_display_and_free(void);

static void	mt_signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		g_server.c |= 1 << g_server.bits;
	g_server.bits++;
	if (g_server.bits >= 8)
	{
		if (mt_char_add())
		{
			mt_display_and_free();
			ft_printf("\nan error occur, the message maybe ");
			ft_printf("\nincomplete or absent");
		}
		if (!g_server.c)
			mt_display_and_free();
		g_server.c = 0;
		g_server.bits = 0;
	}
}

static int	mt_char_add(void)
{
	int	shift;

	if (g_server.buff_free_space < 1)
	{
		if (mt_buff_expand())
			return (1);
		g_server.buff_total_size += BUFF_SIZE;
		g_server.buff_free_space = BUFF_SIZE;
	}
	shift = g_server.buff_total_size - g_server.buff_free_space;
	*(g_server.buff + shift) = g_server.c;
	g_server.buff_free_space--;
	return (0);
}

static int	mt_buff_expand(void)
{
	char	*ptr;
	int		new_size;
	int		i;

	ptr = g_server.buff;
	new_size = g_server.buff_total_size + BUFF_SIZE;
	g_server.buff = ft_calloc(sizeof(char), new_size + 1);
	if (!g_server.buff)
		return (1);
	if (!ptr)
		return (0);
	i = 0;
	while (ptr[i])
	{
		g_server.buff[i] = ptr[i];
		i++;
	}
	free(ptr);
	return (0);
}

static void	mt_display_and_free(void)
{
	ft_printf("%s\n", g_server.buff);
	free(g_server.buff);
	g_server.buff = NULL;
	g_server.buff_total_size = 0;
	g_server.buff_free_space = 0;
}

int	main(void)
{
	struct sigaction	si;

	ft_printf("|******** SERVER ********|\n");
	ft_printf("The Process PID is: %d\n", getpid());
	sigemptyset(&si.sa_mask);
	si.sa_sigaction = mt_signal_handler;
	si.sa_flags = SA_RESTART;
	g_server.c = 0;
	g_server.bits = 0;
	g_server.buff = NULL;
	g_server.buff_free_space = 0;
	g_server.buff_total_size = 0;
	sigaction(SIGUSR1, &si, NULL);
	sigaction(SIGUSR2, &si, NULL);
	while (1)
		pause();
	return (0);
}
