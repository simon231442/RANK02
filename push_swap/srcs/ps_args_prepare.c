/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_prepare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:37:40 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/28 09:37:40 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_args_check_all(int ac, char **args);

char	**ps_args_prepare(int ac, char **av)
{
	int	i;
	char **args;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			i++;
			if(av[1][i] == ' ')
				args = ft_split(av[1], ' ');
		}
		if (av[1][i] != ' ')
			exit(EXIT_SUCCESS);
	}
	if (!args)
	{
		args = malloc(sizeof(char *) * ac);
		if (!args)
			ps_args_error();
		while (av[i])
		{
			args[i] = ft_strdup(av[i]);
			if (!args[i])
				ps_error(args);
			i++;
		}
	}
	ps_args_check_all(ac, args);
	return (args);
}

static void	ps_args_check_all(int ac, char **args)
{
	ps_args_check_no_arg(ac, args);
	ps_args_check_non_numeric(args);
}