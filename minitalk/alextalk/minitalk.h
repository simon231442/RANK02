/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:04:11 by aledos-s          #+#    #+#             */
/*   Updated: 2025/01/17 14:22:24 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* MINITALK ********************************* */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h> // pour les support Unicode 32 bits
# include "./libft/libft.h"
# include "libft/printf/ft_printf.h"

/*
struct sigaction {
    void     (*sa_handler)(int);           // Ancien style gestionnaire de signal
    void     (*sa_sigaction)(siginfo_t *);// Nouveau style gestionnaire
    sigset_t   sa_mask;                  // Signaux à bloquer pendant l'exécution
    int        sa_flags;                // Options de comportement
    void     (*sa_restorer)(void);     // Déprécié, ne pas utiliser
};
*/

typedef struct g_message
{
	char			c;
	int				bits;
	int				client_pid;
	int				received;

}	t_message;

extern t_message	g_msg;

/* ********************************* SERVER ********************************* */

void	ft_btoa(int bit, siginfo_t *info, void *context);

/* ********************************* CLIENT ********************************* */

void	send_bit(int pid, char *str, size_t len);

#endif
