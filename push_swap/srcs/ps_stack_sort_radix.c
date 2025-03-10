/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_sort_radix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:55:04 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 15:55:04 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  ps_get_max_bits(int i_max);

void	ps_stack_sort_radix(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	bits;
	
	bits = ps_get_max_bits(len -1);
}

static int  ps_get_max_bits(int i_max)
{
	int	bits;

	bits = 0;
	while ((i_max - 1) >> bits)
		bits++;
	return (bits);
}
