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
# include <stdio.h>

# define BUFF_SIZE 3
# define TIME_PER_BIT 500

typedef struct	s_server
{
	unsigned char	c;
	int				bits;
	int				buff_free_space;
	int				buff_total_size;
	char			*buff;

}	t_server;

typedef struct	s_client
{
	int		pid;
	char	*msg;
	int		i;
	int		bits;
}	t_client;

#endif
