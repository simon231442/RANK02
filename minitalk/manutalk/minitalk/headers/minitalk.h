/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelma <manuelma@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:09:54 by manuelmarti       #+#    #+#             */
/*   Updated: 2025/02/06 04:59:37 by manuelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

# ifdef __APPLE__
#  define PID_MAX 99999
# elif __x86_64__
#  define PID_MAX 4194304
# else
#  define PID_MAX 32768
# endif

// nbr de milisecondes avant timeout
# define TIME_OUT_MS 600

// nbr de microsecondes entre l'envoi de 2 bits
# define TIME_PER_BIT_US 300

// liste chainee pour stocker les chars du string recu
typedef struct s_chars
{
	char			c;
	struct s_chars	*next;
}	t_chars;

#endif