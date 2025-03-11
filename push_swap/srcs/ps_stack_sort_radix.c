/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_sort_radix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:55:04 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 08:16:41 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_get_max_bits(int i_max);

void	ps_stack_sort_radix(t_stack **stack_a, t_stack **stack_b, int len)
{
	int		bits_max;
	int		bits;
	int		i;

	bits_max = ps_get_max_bits(len -1);
	bits = 0;
	while (bits <= bits_max)
	{
		i = 0;
		while (i < len)
		{
			if ((*stack_a)->position >> bits & 1)
				ps_stack_move_ra(stack_a);
			else
				ps_stack_move_pb(stack_a, stack_b);
			i++;
		}
		while (*stack_b)
			ps_stack_move_pa(stack_a, stack_b);
		bits++;
	}
}

static int	ps_get_max_bits(int i_max)
{
	int	bits;

	bits = 0;
	while ((i_max - 1) >> bits)
		bits++;
	return (bits);
}
