/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:43:55 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/06 23:36:17 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_args	*args;
	
	args = ps_args_struct_init();
	ps_args_prepare(ac, av, args);
	ps_args_count(args);
	ps_args_to_int_tab(args);
	ps_args_int_sort(args);
	ps_stack_a_create(args);
	/*
	ft_printf("stack a\n");
	while (args->stack_a)
	{
		ft_printf("%d\n", args->stack_a->position);
		args->stack_a = args->stack_a->next;
	}
	*/
	ps_args_free(args);
	return (0);
}
