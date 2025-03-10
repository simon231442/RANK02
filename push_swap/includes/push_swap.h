/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:12:32 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/10 12:50:40 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				position;
	struct s_stack	*next;
}	t_stack;

typedef struct s_args
{
	char	**s_char;
	int		len;
	int		*int_desorder;
	int		*int_sorted;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_args;

t_args	*ps_args_struct_init(void);
void	ps_args_prepare(int ac, char **av, t_args *self);
void	ps_args_check_non_numeric(t_args *self);
void	ps_args_check_over_and_underflow(t_args *self);
void	ps_args_check_duplicate(t_args *self);
void	ps_args_count(t_args *self);
void	ps_args_to_int_tab(t_args *self);
void	ps_args_int_sort(t_args *self);
void	ps_args_free(t_args *self);
void	ps_stack_a_create(t_args *args);
void	ps_error(t_args *args);
void	ps_stack_move_utils_swap(t_stack **stack);
void	ps_stack_move_sa(t_stack **stack_a);
void	ps_stack_move_sb(t_stack **stack_b);
void	ps_stack_move_ss(t_stack **stack_a, t_stack **stack_b);
void	ps_stack_move_utils_push(t_stack **stack_a, t_stack **stack_b);
void	ps_stack_move_pa(t_stack **stack_a, t_stack **stack_b);
void	ps_stack_move_pb(t_stack **stack_a, t_stack **stack_b);
void	ps_stack_move_utils_rotate(t_stack **stack);
void	ps_stack_move_ra(t_stack **stack_a);
void	ps_stack_move_rb(t_stack **stack_b);
void	ps_stack_move_rr(t_stack **stack_a, t_stack **stack_b);
void	ps_stack_move_utils_reverse_rotate(t_stack **stack);
void	ps_stack_move_rra(t_stack **stack_a);
void	ps_stack_move_rrb(t_stack **stack_b);
void	ps_stack_move_rrr(t_stack **stack_a, t_stack **stack_b);

void	ps_stack_utils_display(t_stack *stack_a, t_stack *stack_b);

#endif
