/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:46:37 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 11:00:43 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_sort(t_args *args)
{
	if (args->len == 2)
		ps_stack_move_sa(&args->stack_a);
	else if (args->len == 3)
		ps_stack_sort_3(&args->stack_a);
	else if (args->len == 4)
		ps_stack_sort_4(&args->stack_a, &args->stack_b);
	else if (args->len == 5)
		ps_stack_sort_5(&args->stack_a, &args->stack_b, args->len - 1);
	else
		ps_stack_sort_radix(&args->stack_a, &args->stack_b, args->len);
}	
