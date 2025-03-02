/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_prepare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:37:40 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/02 15:34:58 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_args_check_all(int ac, char **self);

char	**ps_args_prepare(int ac, char **av)
{
	int	i;
	char **args;

	i = 0;
	args = NULL;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			ps_error(args);
	}
	else
	{
		args = malloc(sizeof(char *) * ac);
		if (!args)
			ps_error(args);
		while (av[i + 1])
		{
			args[i] = ft_strdup(av[i + 1]);
			if (!args[i])
				ps_error(args);
			i++;
		}
	}
	ps_args_check_all(ac, args);
	return (args);
}

static void	ps_args_check_all(int ac, char **self)
{
	ft_printf("no arg :		 ");
	ps_args_check_no_arg(ac, self);
	ft_printf("ok\nnon numeric :		 ");
	ps_args_check_non_numeric(self);
	ft_printf("ok\nover and underflow :	 ");
	ps_args_check_over_and_underflow(self);
	ft_printf("ok\n");
}
