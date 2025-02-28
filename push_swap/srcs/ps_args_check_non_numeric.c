/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_check_non_numeric.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:11:18 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/27 23:11:18 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_args_check_non_numeric(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i][j] != '-' || args[i][j] < '0' || args[i][j] > '9')
			ps_error(args);
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
			ps_error(args);
			j++;
		}
		i++;
	}
}