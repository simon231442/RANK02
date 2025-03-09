/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:39:31 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/08 15:15:55 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_stack **stack_a)
{
	t_stack	*node3eme;

	node3eme = (*stack_a)->next->next;//enregistrer l'addresse du 3eme node
	(*stack_a)->next->next = *stack_a;//faire pointer le 2eme node sur le premier
	*stack_a = (*stack_a)->next; 	//faire pointer le pointeur de tete sur le 2eme node
	(*stack_a)->next->next = node3eme;//faire pointer le 1er node sur le troisieme

/*
	node0 = stack_a->next;
	node0->next = stack_a->next->next;
	node1 = stack_a->next;
	node1->next = stack_a->next->next;
	stack_a = node0;
	stack_a->next = node0->next;
	stack_a->next->next = node1->next;
*/
	ft_putstr_fd("sa\n", 1);
}
