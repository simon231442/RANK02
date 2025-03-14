/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:43:55 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 14:48:51 by srenaud          ###   ########.fr       */
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
	ft_printf("Desorder: \n");
	ps_args_int_utils_display(args->int_desorder, args->len);
	ft_printf("sorted: \n");
	ps_args_int_utils_display(args->int_sorted, args->len);
	ps_args_check_already_sorted(args);
	ps_stack_a_create(args);
	ft_printf("stack: \n");
	ps_stack_utils_display_line(args->stack_a);
//	ps_stack_sort(args);
	ps_args_free(args);
	return (0);
}
