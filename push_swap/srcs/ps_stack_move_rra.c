/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_rra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:38:13 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 13:09:11 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_rra(t_stack **stack_a)
{
	ps_stack_move_utils_reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}
