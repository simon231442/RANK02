/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:37:55 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/09 20:37:55 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_stack_move_rr(t_stack **stack_a, t_stack **stack_b)
{
		ps_stack_move_utils_rotate(stack_a);
		ps_stack_move_utils_rotate(stack_b);
		ft_putstr_fd("rr\n", 1);
}