/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_pb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:28:30 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 13:12:55 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_pb(t_stack **stack_a, t_stack **stack_b)
{
	ps_stack_move_utils_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
