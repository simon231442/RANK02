/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_sort_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:06:00 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 11:21:50 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_sort_5(t_stack **stack_a, t_stack **stack_b, int i_max)
{
	while ((*stack_a)->position != 0 && (*stack_a)->position != i_max)
		ps_stack_move_ra(stack_a);
	ps_stack_move_pb(stack_a, stack_b);
	while ((*stack_a)->position != 0 && (*stack_a)->position != i_max)
		ps_stack_move_ra(stack_a);
	ps_stack_move_pb(stack_a, stack_b);
	ps_stack_sort_3(stack_a);
	if ((*stack_b)->position == i_max)
		ps_stack_move_sb(stack_b);
	ps_stack_move_pa(stack_a, stack_b);
	ps_stack_move_pa(stack_a, stack_b);
	ps_stack_move_ra(stack_a);
}
