/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_sa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:39:34 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/08 15:43:52 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_sa(t_stack **stack_a)
{
	ps_stack_move_utils_swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

