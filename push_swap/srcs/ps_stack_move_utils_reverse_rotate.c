/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_utils_reverse_rotate.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:37:14 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/09 20:31:54 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_stack_move_utils_reverse_rotate(t_stack **stack)
{
        t_stack *first;
        t_stack *second2last;

	first = *stack;
	second2last = first;
	while (second2last->next->next)
		second2last= second2last->next;
	*stack = second2last->next;
	(*stack)->next = first;
	second2last->next = NULL;
}



