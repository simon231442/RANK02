/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:43:55 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 08:18:05 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_args	*args;
//	int		i = 0; 		//test

	args = ps_args_struct_init();
	ps_args_prepare(ac, av, args);
	ps_args_count(args);
	ps_args_to_int_tab(args);
	ps_args_int_sort(args);
	ps_args_check_already_sorted(args);
	ps_stack_a_create(args);
	ps_stack_sort_radix(&args->stack_a, &args->stack_b, args->len);
/*
	ps_stack_utils_display(args->stack_a, args->stack_b);

	while (i < 5)
	{
		ps_stack_move_pb(&args->stack_a, &args->stack_b);
		i++;
	}

	ps_stack_utils_display(args->stack_a, args->stack_b);
	
	i = 0;
	while (i < 1)
	{
		ps_stack_move_pa(&args->stack_a, &args->stack_b);
		i++;
	}
	
	ps_stack_utils_display(args->stack_a, args->stack_b);

	ps_stack_move_ra(&args->stack_a);
	ps_stack_move_rb(&args->stack_b);

	ps_stack_utils_display(args->stack_a, args->stack_b);

	ps_stack_move_rrr(&args->stack_a, &args->stack_b);

	ps_stack_utils_display(args->stack_a, args->stack_b);



	ps_stack_move_rra(&args->stack_a);
	ps_stack_move_rrb(&args->stack_b);

	ps_stack_utils_display(args->stack_a, args->stack_b);

	ps_stack_move_rr(&args->stack_a, &args->stack_b);

	ps_stack_utils_display(args->stack_a, args->stack_b);
*/
	ps_args_free(args);
	return (0);
}
