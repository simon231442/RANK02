/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_rb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:28:42 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 13:07:23 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_move_rb(t_stack **stack_b)
{
	ps_stack_move_utils_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}
