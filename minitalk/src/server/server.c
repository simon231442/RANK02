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

t_message	g_msg;


static void	mt_display()
{
	ft_printf("%s", g_msg.buff);
	//free buff et tmp
}
static void	mt_char_add()
{
	//char	*ptr;

	if (g_msg.tmp_level == BUFF_SIZE)
	{
		//ptr = g_msg.buff;
		g_msg.buff = ft_strcat(g_msg.buff, g_msg.tmp);//a free
		//free buff et tmp
		g_msg.tmp_level = 0;
		g_msg.tmp = ft_calloc(sizeof(char), BUFF_SIZE + 1);
		//free
	}
	g_msg.tmp[g_msg.tmp_level] = g_msg.c;
	g_msg.tmp_level++;
}

static void	mt_signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (g_msg.bits < 8 && signum == SIGUSR2)
		g_msg.c |= (1 << g_msg.bits);
	if (g_msg.bits == 8)
	{
		mt_char_add();
		g_msg.bits = 0;
	}
	if (g_msg.bits == 8 && !g_msg.c)
		mt_display();
}	

int	main(void)
{
	struct	sigaction si;
	
	ft_printf("|******** SERVER ********|\n");
	ft_printf("The Process PID is: %d\n", getpid());
	sigemptyset(&si.sa_mask);
	si.sa_sigaction = mt_signal_handler;
	si.sa_flags = SA_RESTART;
	g_msg.bits = 0;
	g_msg.tmp_level = 0;
	g_msg.buff = ft_calloc(sizeof(char), 1); //a free
	g_msg.tmp = ft_calloc(sizeof(char), BUFF_SIZE + 1); //a free
	sigaction(SIGUSR1, &si, NULL);
	sigaction(SIGUSR2, &si, NULL); 
	return(0);
}
/*
Serveur

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    char c;
    int bits;
    int client_pid;
} t_message;

extern t_message g_msg; //c'est quoi extern?

void mt_server_init(); //quelle fonction vais-je appeler dans celle la?

void mt_signal_handler(int signum, siginfo_t *info, void *context);// ou la variable signinfo_t est delaree?
// quel est sa definition
void mt_process_signal(int signum, siginfo_t *info); // que defini process ?
void mt_display_message();

int mt_server_main();
*/