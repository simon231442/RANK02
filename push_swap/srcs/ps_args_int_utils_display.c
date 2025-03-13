/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_int_utils_display.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:02:08 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/11 19:02:08 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_args_int_utils_display(int *self, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d ", self[i]);
		i++;
	}
	ft_printf("\n");
}
