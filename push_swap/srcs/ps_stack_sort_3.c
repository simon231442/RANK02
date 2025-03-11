/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_sort_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:04:20 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 11:23:16 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_stack_sort_3_next(t_stack **stack_a);

void	ps_stack_sort_3(t_stack **stack_a)
{
	if ((*stack_a)->next->next->position < (*stack_a)->position
		&& (*stack_a)->next->position < (*stack_a)->position
		&& (*stack_a)->next->position < (*stack_a)->next->next->position)
		ps_stack_move_ra(stack_a);
	else if ((*stack_a)->position < (*stack_a)->next->position
		&& (*stack_a)->position < (*stack_a)->next->next->position
		&& (*stack_a)->next->position > (*stack_a)->next->next->position)
	{
		ps_stack_move_sa(stack_a);
		ps_stack_move_ra(stack_a);
	}
	else if ((*stack_a)->position > (*stack_a)->next->position
		&& (*stack_a)->position > (*stack_a)->next->next->position
		&& (*stack_a)->next->position > (*stack_a)->next->next->position)
	{
		ps_stack_move_ra(stack_a);
		ps_stack_move_sa(stack_a);
	}
	else
		ps_stack_sort_3_next(stack_a);
}

static void	ps_stack_sort_3_next(t_stack **stack_a)
{
	if ((*stack_a)->position > (*stack_a)->next->position
		&& (*stack_a)->position < (*stack_a)->next->next->position
		&& (*stack_a)->next->position < (*stack_a)->next->next->position)
		ps_stack_move_sa(stack_a);
	else if ((*stack_a)->position > (*stack_a)->next->next->position
		&& (*stack_a)->position < (*stack_a)->next->position
		&& (*stack_a)->next->position > (*stack_a)->next->next->position)
	{
		ps_stack_move_ra(stack_a);
		ps_stack_move_ra(stack_a);
	}
}
