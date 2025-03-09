/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_move_pa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:28:18 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/09 16:34:57 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_stack_move_pa(t_stack **stack_a, t_stack **stack_b)
{
        ps_stack_move_utils_push(stack_b, stack_a);
        ft_putstr_fd("pa\n", 1);
}

