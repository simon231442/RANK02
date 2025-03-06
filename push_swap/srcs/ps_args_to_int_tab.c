/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_to_int_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:42:54 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/04 12:22:42 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_args_to_int_tab(t_args *self)
{
	int	i;

	self->int_desorder = malloc(sizeof(int) * self->len);
	if (!self->int_desorder)
		ps_error(self);
	self->int_sorted = malloc(sizeof(int) * self->len);
	if (!self->int_sorted)
		ps_error(self);
	i = 0;
	while (self->s_char[i])
	{
		self->int_desorder[i] = ft_atoi(self->s_char[i]);
		self->int_sorted[i] = self->int_desorder[i];
		i++;
	}
}

