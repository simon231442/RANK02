/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils_display_line.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:33:53 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 13:54:00 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_utils_display_line(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("%d ", stack_a->position);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}
