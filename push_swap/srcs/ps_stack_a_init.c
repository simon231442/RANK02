/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_a_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:50:02 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 13:26:09 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	number_chr(int *arg_disorder, int number);

t_stack	*ps_stack_a_first(int *arg_disorder, int *arg_sorted, int len)
{
	t_stack	stack_a;
	int		i;

	i = 0;
	stack_a = malloc(sizeof(t_stack *));
	stack_a->index = 0;
	stack_a->postion = number_chr(arg_disorder, i);
	stack_a->next = NULL;
}

static int	number_chr(int *arg_disorder, int number)
{
	int	i;

	i = 0;
	while (arg_disorder[i] != number)
		i++;
	return (i);
}
