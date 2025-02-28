/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:12:32 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/27 14:12:32 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

void	ps_args_check_no_arg(int ac);
void	ps_args_error(void);

#endif