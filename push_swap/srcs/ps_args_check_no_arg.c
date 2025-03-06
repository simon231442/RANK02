/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_check_no_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:17:23 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/02 15:33:19 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_args_check_no_arg(int ac, t_args *self)
{
	if (ac == 1)
		ps_error(self);
/*	if (!self->s_char[1])
	{
		free(self->s_char[0]);
		free(self->s_char);
		exit(EXIT_SUCCESS);
	}
*/
}
