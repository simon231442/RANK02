/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_a_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:01:03 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/04 10:49:10 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ps_stack_a_new(int position);
static int		number_chr(int *arg_disorder, int number);
static void		ps_stack_a_addback(t_stack **stack_a, t_stack *new);

t_stack	*ps_stack_a_create(int *arg_disorder, int *arg_sorted, int len)
{
	t_stack		*stack_a;
	t_stack		*ptr;
	int			i;

	i = 0;
	stack_a = ps_stack_a_new(number_chr(arg_disorder, arg_sorted[i]));
	ptr = stack_a;
	i++;
	while (i < len)
	{
		ptr = ps_stack_a_new(number_chr(arg_disorder, arg_sorted[i]));
		ps_stack_a_addback(&stack_a, ptr);
		i++;
	}
	return (stack_a);
}

t_stack	*ps_stack_a_new(int position)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->position = position;
	new->next = NULL;
	return (new);
}

static int	number_chr(int *arg_disorder, int number)
{
	int	i;

	i = 0;
	while (arg_disorder[i] != number)
		i++;
	return (i);
}

void	ps_stack_a_addback(t_stack **stack_a, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
