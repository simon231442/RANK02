/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_rrb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:38:34 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 13:09:46 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_rrb(t_stack **stack_b)
{
	ps_stack_move_utils_reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}
