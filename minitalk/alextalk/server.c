/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:04:15 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/17 13:57:55 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	g_msg = {0, 0, 0, 0};

void	ft_btoa(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR2)
		g_msg.c |= (1 << g_msg.bits);
	g_msg.bits++;
	if (g_msg.bits == 8)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.bits = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("|******** SERVER ********|\n");
	ft_printf("The Process PID is: \033[0;32m%d ✔\033[0m\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_btoa;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
