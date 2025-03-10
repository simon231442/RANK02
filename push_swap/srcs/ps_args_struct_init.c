/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_struct_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:30:20 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 12:36:41 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_args	*ps_args_struct_init(void)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	args->s_char = NULL;
	args->int_desorder = NULL;
	args->int_sorted = NULL;
	args->stack_a = NULL;
	args->stack_b = NULL;
	return (args);
}
