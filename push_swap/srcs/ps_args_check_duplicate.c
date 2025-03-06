/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_check_duplicate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:00:50 by srenaud           #+#    #+#             */
/*   Updated: 2025/03/03 00:52:19 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_args_cmp(const char *s1, const char *s2, t_args *self);

void	ps_args_check_duplicate(t_args *self)
{
	int	i;
	int	j;

	i = 0;
	while (self->s_char[i])
	{
		j = i + 1;
		while (self->s_char[j])
		{
			ps_args_cmp(self->s_char[i], self->s_char[j], self);
			j++;
		}
		i++;
	}
}

static void	ps_args_cmp(const char *s1, const char *s2, t_args *self)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		ps_error(self);
}
