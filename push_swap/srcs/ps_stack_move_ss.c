/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_ss.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:01:56 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/08 16:05:35 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_stack_move_ss(t_stack **stack_a, t_stack **stack_b)
{
        ps_stack_move_utils_swap(stack_a);
        ps_stack_move_utils_swap(stack_b);
        ft_putstr_fd("ss\n", 1);
}

