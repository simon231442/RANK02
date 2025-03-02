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

void	ps_args_check_non_numeric(char **self)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (self[i])
	{
		if (self[i][j] != '-' || self[i][j] < '0' || self[i][j] > '9')
			ps_error(self);
		while (self[i][j])
		{
			if (self[i][j] < '0' || self[i][j] > '9')
				ps_error(self);
			j++;
		}
		i++;
	}
}
