/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:43:55 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/08 16:07:48 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_args	*args;
	t_stack	*ptr;	//test
	
	args = ps_args_struct_init();
	ps_args_prepare(ac, av, args);
	ps_args_count(args);
	ps_args_to_int_tab(args);
	ps_args_int_sort(args);
	ps_stack_a_create(args);
	


	ptr = args->stack_a;
	ft_printf("stack a\n");
	while (ptr)
	{
		ft_printf("%d\n", ptr->position);
		ptr = ptr->next;
	}
	ft_printf("\n");
	ps_stack_move_utils_swap(&args->stack_a);
	ptr = args->stack_a;
	while (ptr)
	{
		ft_printf("%d\n", ptr->position);
		ptr = ptr->next;
	}



	ps_args_free(args);
	return (0);
}
