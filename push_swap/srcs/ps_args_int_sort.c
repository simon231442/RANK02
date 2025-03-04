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

void	ps_args_int_sort(int *self, int len)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (j < len)
	{
		if (self[i] > self[j])
		{
			ps_int_swap(&self[i], &self[j]);
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

