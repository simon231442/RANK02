/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:29:39 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/28 12:59:04 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server;

static void	mt_display_and_free(void)
{
	ft_printf("%s", g_server.buff);
	if (g_server.buff)
		free(g_server.buff);
	if (g_server.tmp)
		free(g_server.tmp);
}

static void	mt_char_add(void)
{
	char	*ptr;

	if (g_server.tmp_level == BUFF_SIZE)
	{
		ptr = g_server.buff;
		g_server.buff = ft_strcat(g_server.buff, g_server.tmp);
		if (!g_server.buff)
			mt_display_and_free();
		free(ptr);
		free(g_server.tmp);
		g_server.tmp = ft_calloc(sizeof(char), BUFF_SIZE + 1);
		if (!g_server.tmp)
			mt_display_and_free();
		g_server.tmp_level = 0;
	}
	g_server.tmp[g_server.tmp_level] = g_server.c;
	g_server.tmp_level++;
}

static void	mt_signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (g_server.bits < 8 && signum == SIGUSR1)
		g_server.c |= (1 << g_server.bits);
	g_server.bits++;
	if (g_server.bits == 8)
	{
		mt_char_add();
		if (!g_server.c)
			mt_display_and_free();
		g_server.bits = 0;
		g_server.c = 0;
	}
}

int	main(void)
{
	struct sigaction	si;

	ft_printf("|******** SERVER ********|\n");
	ft_printf("The Process PID is: %d\n", getpid());
	sigemptyset(&si.sa_mask);
	si.sa_sigaction = mt_signal_handler;
	si.sa_flags = SA_RESTART;
	g_server.bits = 0;
	g_server.tmp_level = 0;
	g_server.buff = ft_calloc(sizeof(char), 1);
	if (!g_server.buff)
		mt_display_and_free();
	g_server.tmp = ft_calloc(sizeof(char), BUFF_SIZE + 1);
	if (!g_server.tmp)
		mt_display_and_free();
	sigaction(SIGUSR1, &si, NULL);
	sigaction(SIGUSR2, &si, NULL);
	while (1)
		pause();
	return (0);
}
