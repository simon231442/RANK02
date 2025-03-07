/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_prepare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:37:40 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/04 13:22:44 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_args_copy(int ac, char **av, t_args *self);

static void	ps_args_check_all(int ac, t_args *self);

	void	ps_args_prepare(int ac, char **av, t_args *self)
{
	if (ac == 2)
	{
		self->s_char = ft_split(av[1], ' ');
		if (!self)
			ps_error(self);
	}
	else
		ps_args_copy(ac, av, self);
	ps_args_check_all(ac, self);
}

static void	ps_args_copy(int ac, char **av, t_args *self)
{
	int		i;

	i = 0;
	self->s_char = ft_calloc(sizeof(char *), ac);
	if (!self->s_char)
		ps_error(self);
	while (av[i + 1])
	{
		self->s_char[i] = ft_strdup(av[i + 1]);
		if (!self->s_char[i])
			ps_error(self);
		i++;
	}
}

static void	ps_args_check_all(int ac, t_args *self)
{
	ps_args_check_no_arg(ac, self);
	ps_args_check_non_numeric(self);
	ps_args_check_over_and_underflow(self);
	ps_args_check_duplicate(self);
}
