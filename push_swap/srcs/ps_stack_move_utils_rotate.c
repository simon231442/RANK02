/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_utils_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:46:59 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 13:17:10 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_utils_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	*stack = first->next;
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}
