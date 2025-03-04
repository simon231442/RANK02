/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:43:55 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/04 13:25:47 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	int	len;
	int	*arg_desorder;
	int	*arg_sorted;
	t_stack	*stack_a;

	args = ps_args_prepare(ac, av);
	len = ps_args_count(args);
	arg_desorder = malloc(sizeof(int) * len);
	arg_sorted = malloc(sizeof(int) * len);
	ps_args_to_int_tab(args, arg_desorder);
	ps_args_to_int_tab(args, arg_sorted);
	ps_args_free(args);
	ps_args_int_sort(arg_sorted, len);
	stack_a = ps_stack_a_create(arg_desorder, arg_sorted, len);
	
	ft_printf("stack a\n");
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->position);
		stack_a = stack_a->next;
	}
	return (0);
}
