/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_to_int_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:42:54 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/03 08:42:54 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_args_to_int_tab(char **args, int *args_int)
{
	int	i;

	i = 0;
	while (args[i])
	{
		args_int[i] = ft_atoi((char *)args[i]);
		i++;
	}
}

