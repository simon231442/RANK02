/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_int_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:42:22 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/03 09:42:22 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_int_swap(int *n1, int *n2);

void	ps_args_int_sort(t_args *self)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (j < self->len)
	{
		if (self->int_sorted[i] > self->int_sorted[j])
		{
			ps_int_swap(&self->int_sorted[i], &self->int_sorted[j]);
			i = 0;
			j = i + 1;
		}
		else
		{
			i++;
			j++;
		}
	}
}

static void	ps_int_swap(int *n1, int *n2)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

