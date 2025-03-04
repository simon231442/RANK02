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

static char	**ps_args_copy(int ac, char **av);

static void	ps_args_check_all(int ac, char **self);

char	**ps_args_prepare(int ac, char **av)
{
	char	**self;

	if (ac == 2)
	{
		self = ft_split(av[1], ' ');
		if (!self)
			ps_error(self);
	}
	else
		self = ps_args_copy(ac, av);
	ps_args_check_all(ac, self);
	return (self);
}

static char	**ps_args_copy(int ac, char **av)
{
	char	**self;
	int		i;

	i = 0;
	self = malloc(sizeof(char *) * ac);
	if (!self)
		ps_error(self);
	while (av[i + 1])
	{
		self[i] = ft_strdup(av[i + 1]);
		if (!self[i])
			ps_error(self);
		i++;
	}
	return (self);
}

static void	ps_args_check_all(int ac, char **self)
{
	ps_args_check_no_arg(ac, self);
	ps_args_check_non_numeric(self);
	ps_args_check_over_and_underflow(self);
	ps_args_check_duplicate(self);
}
