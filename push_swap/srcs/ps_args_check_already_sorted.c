/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_check_already_sorted.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:07:59 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 08:00:43 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_args_check_already_sorted(t_args *self)
{
	int	i;

	i = 0;
	while (i < self->len)
	{
		if (self->int_desorder[i] != self->int_sorted[i])
			return ;
		i++;
	}
	ps_args_free(self);
	exit(EXIT_SUCCESS);
}
