/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_check_non_numeric.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:11:18 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/27 23:11:18 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_args_check_non_numeric(t_args *self)
{
	int	i;
	int	j;

	i = 0;
	while (self->s_char[i])
	{
		j = 0;
		if ((self->s_char[i][j] < '0' || self->s_char[i][j] > '9') 
			&& self->s_char[i][j] != '-')
			ps_error(self);
		j++;
		while (self->s_char[i][j])
		{
			if (self->s_char[i][j] < '0' || self->s_char[i][j] > '9')
				ps_error(self);
			j++;
		}
		i++;
	}
}
