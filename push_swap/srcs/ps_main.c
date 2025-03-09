/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:43:55 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/09 19:11:09 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_args	*args;
	t_stack	*ptr_a;	//test
	t_stack	*ptr_b;	//test
	
	args = ps_args_struct_init();
	ps_args_prepare(ac, av, args);
	ps_args_count(args);
	ps_args_to_int_tab(args);
	ps_args_int_sort(args);
	ps_stack_a_create(args);

	ptr_a = args->stack_a;
	ptr_b = args->stack_b;
	ft_printf("stack a		stack b\n");
	while (ptr_a)
	{
		ft_printf("%d", ptr_a->position);
		ptr_a = ptr_a->next;
		if (ptr_b)
		{
			ft_printf("		%d\n", ptr_b->position);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n");
	ps_stack_move_utils_reverse_rotate(&args->stack_a);
	ptr_a = args->stack_a;
	ptr_b = args->stack_b;
	ft_printf("stack a		stack b\n");
	while (ptr_a)
	{
		ft_printf("%d", ptr_a->position);
		ptr_a = ptr_a->next;
		if (ptr_b)
		{
			ft_printf("		%d\n", ptr_b->position);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n");
	ps_args_free(args);
	return (0);
}
