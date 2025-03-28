/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:04:11 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/17 15:37:26 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	g_msg = {0, 0, 0, 0};

void	confirm_handler(int signum)
{
	(void)signum;
	g_msg.received = 1;
}

void	bit_by_bit(int pid, int shift, unsigned char c)
{
	if ((c >> shift) & 1)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit (1);
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			exit (1);
	}
}

void	send_bit(int pid, char *str, size_t len)
{
	int				shift;
	size_t			i;
	unsigned char	c;

	i = 0;
	while (i <= len)
	{
		c = (unsigned char)str[i];
		shift = 0;
		while (shift < 8)
		{
			g_msg.received = 0;
			bit_by_bit(pid, shift, c);
			usleep(500);
			while (!g_msg.received)
				usleep(100);
			shift++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	char				*msg;

	if (argc != 3)
	{
		ft_printf("\n./client <PID number> <blabla>\n\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID");
		return (1);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = confirm_handler;
	sa.sa_flags = SA_RESTART;
//	if (sigaction(SIGUSR1, &sa, NULL) == -1)
//		ft_printf("erreur de config du signal\n");
	msg = argv[2];
	send_bit(pid, msg, ft_strlen(msg));
	ft_printf("\033[0;32m✔ Message envoyé avec succès !\033[0m");
	return (0);
}
