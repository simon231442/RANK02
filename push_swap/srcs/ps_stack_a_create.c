/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_a_create.c                                 :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:01:03 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/19 15:01:38 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ps_stack_a_new(int position);
static int		ps_get_position(int *arg_desorer, int index, int len);
static void		ps_stack_a_addback(t_stack **stack_a, t_stack *new);

void	ps_stack_a_create(t_args *args)
{
	t_stack		*ptr;
	int			i;
	int			position;

	i = 0;
	position = ps_get_position(args->int_desorder, i, args->len);
	args->stack_a = ps_stack_a_new(position);
	if (!args->stack_a)
		ps_error(args);
	ptr = args->stack_a;
	i++;
	while (i < args->len)
	{
		position = ps_get_position(args->int_desorder, i, args->len);
		ptr = ps_stack_a_new(position);
		if (!ptr)
			ps_error(args);
		ps_stack_a_addback(&args->stack_a, ptr);
		i++;
	}
}

t_stack	*ps_stack_a_new(int position)
{
	t_stack	*new;

	new = calloc(sizeof(t_stack), 1);
	if (!new)
		return (NULL);
	new->position = position;
	new->next = NULL;
	return (new);
}

static int	ps_get_position(int	*arg_desorer, int index, int len)
{
	int	i;
	int	position;

	i = 0;
	position = 0;
	while (i < len)
	{
		if (arg_desorer[index] > arg_desorer[i])
			position++;
		i++;
	}
	return (position);
}

void	ps_stack_a_addback(t_stack **stack_a, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
