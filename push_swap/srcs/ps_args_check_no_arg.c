/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_check_no_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:17:23 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/02 15:33:19 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_args_check_no_arg(int ac, char **self)
{
	int	i;

	if (ac == 1)
		ps_error(NULL);
	i = 0;
	while (self[i])
		i++;
	if (i == 1)
	{
		free(self);
		exit(EXIT_SUCCESS);
	}
}
