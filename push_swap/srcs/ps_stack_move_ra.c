/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_ra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:25:12 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 13:06:21 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_ra(t_stack **stack_a)
{
	ps_stack_move_utils_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}
