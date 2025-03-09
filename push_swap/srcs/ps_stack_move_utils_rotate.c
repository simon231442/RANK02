/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_utils_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:46:59 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/09 17:20:48 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_utils_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack *second;
	t_stack	*second2last;

	first = *stack;
	second = (*stack)->next;
	second2last = second;
	while (second2last->next->next)
		second2last = second2last->next;
	*stack = second2last->next;	//la tete pointe sur le dernier
	(*stack)->next = second;	//le nouveau premier point sur le deuxieme
	second2last->next = first;
	first->next = NULL;
}
