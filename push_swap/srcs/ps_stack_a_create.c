/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_a_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:01:03 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 08:06:03 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ps_stack_a_new(int position);
static int		number_chr(int *arg_disorder, int number);
static void		ps_stack_a_addback(t_stack **stack_a, t_stack *new);

void	ps_stack_a_create(t_args *args)
{
	t_stack		*ptr;
	int			i;
	int			position;

	i = 0;
	position = number_chr(args->int_desorder, args->int_sorted[i]);
	args->stack_a = ps_stack_a_new(position);
	if (!args->stack_a)
		ps_error(args);
	ptr = args->stack_a;
	i++;
	while (i < args->len)
	{
		position = number_chr(args->int_desorder, args->int_sorted[i]);
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
