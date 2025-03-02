/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:42:16 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/02 15:02:03 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_args_free(char **self)
{
	int i;

	i = 0;
	if (self != NULL)
	{
		while (self[i])
		{
			free(self[i]);
			i++;
		}
		free(self);
	}
}
