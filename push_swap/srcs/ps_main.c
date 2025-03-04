/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:43:55 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/04 11:42:26 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	int	arg_desorder[ac - 1];
	int	arg_sorted[ac - 1];
	t_stack	*stack_a;

	args = ps_args_prepare(ac, av);
	ps_args_to_int_tab(args, arg_desorder);
	ps_args_to_int_tab(args, arg_sorted);
	ps_args_free(args);
	ps_args_int_sort(arg_sorted, ac - 1);
	stack_a = ps_stack_a_create(arg_desorder, arg_sorted, ac -1);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->position);
		stack_a = stack_a->next;
	}
	return (0);
}
