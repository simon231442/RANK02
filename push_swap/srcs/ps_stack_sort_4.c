/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_sort_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:05:46 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 09:05:46 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->position != 0)
		ps_stack_move_ra(stack_a);
	ps_stack_move_pb(stack_a, stack_b);
	ps_stack_sort_3(stack_a);
	ps_stack_move_pa(stack_a, stack_b);
}
