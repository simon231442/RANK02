/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_utils_push.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:45:17 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/09 14:06:45 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_utils_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack *first_b;

	first_a = *stack_a;
	second_a = (*stack_a)->next;
	first_b = (*stack_b);
	*stack_b = first_a;
	(*stack_b)->next = first_b;
	*stack_a = second_a;
}



