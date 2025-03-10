/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:33:53 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 11:33:54 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_utils_display(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\nA	B\n\n");
	while (stack_a)
	{
		ft_printf("%d", stack_a->position);
		stack_a = stack_a->next;
		if (stack_b)
		{
			ft_printf("	%d\n", stack_b->position);
			stack_b = stack_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n\n");
}
