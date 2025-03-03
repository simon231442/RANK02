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

#include <push_swap.h>

static void	ps_args_cmp(const char *s1, const char *s2, char **self)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		ps_error(self);
}


void	ps_args_check_duplicate(char **self)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (self[i])
	{
		while (self[j])
		{
			if (i == j)
				;
			else 
				ps_args_cmp(self[i], self[j], self);
			j++;
		}
		i++;
	}
}


