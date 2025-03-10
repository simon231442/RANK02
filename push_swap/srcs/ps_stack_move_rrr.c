/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:38:07 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 13:11:04 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ps_stack_move_utils_reverse_rotate(stack_a);
	ps_stack_move_utils_reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
