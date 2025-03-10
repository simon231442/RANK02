/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_sb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:49:03 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 13:23:18 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_sb(t_stack **stack_b)
{
	ps_stack_move_utils_swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}
