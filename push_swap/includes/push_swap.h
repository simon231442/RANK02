/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:12:32 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/03 00:22:55 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>

#include <stdio.h> //debug

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

char	**ps_args_prepare(int ac, char **self);
void	ps_args_check_no_arg(int ac, char **self);
void	ps_args_check_non_numeric(char **self);
void	ps_args_check_over_and_underflow(char **self);
void	ps_args_check_duplicate(char **self);
void    ps_args_free(char **self);
void	ps_error(char **args);

#endif
