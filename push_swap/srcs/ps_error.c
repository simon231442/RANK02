/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:18:50 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/27 23:18:50 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(char **args)
{
	ft_putstr_fd("Error\n", 2);
	ps_args_free(args);
	exit(EXIT_FAILURE);
}
