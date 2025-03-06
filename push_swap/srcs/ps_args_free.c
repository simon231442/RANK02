/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:42:16 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/02 15:02:03 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_args_free(t_args *self)
{
	int 	i;
	t_stack	ptr;

	i = 0;
	if (self->s_char)
	{
		while (self->s_char[i])
		{
			free(self->s_char[i]);
			i++;
		}
		free(self->s_char);
	}
	if (self->int_desorder)
		free(self->int_desorder);
	if (self->int_sorted)
		free(self->int_sorted);
	if (self->stack_a)
		{

}
