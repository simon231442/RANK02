/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:42:16 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/28 11:42:16 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_args_free(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}