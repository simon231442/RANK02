/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:47:04 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/28 15:16:28 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 500
# define TIME_PER_BIT 500

typedef struct	s_message
{
	unsigned char	c;
	int				bits;
	int				cliend_pid;
	int				tmp_level;
	char			*buff;
	char			*tmp;

}	t_message;

typedef struct	s_client
{
	int		pid;
	char	*msg;
	int		i;
	int		bits;
}	t_client;

#endif