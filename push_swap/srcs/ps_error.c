/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:18:50 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/02 15:31:58 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(char **args)
{
	ft_putstr_fd("Error\n", 2);
	if (args == NULL)
		exit(EXIT_FAILURE);
	ps_args_free(args);
	exit(EXIT_FAILURE);
}
