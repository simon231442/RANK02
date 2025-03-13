/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:46:43 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/22 12:04:51 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_putchar(int c, int *len)
{
	*len += write(1, &c, 1);
}

void	pf_putstr(char *str, int *len)
{
	if (str == NULL)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (*str)
		*len += write(1, str++, 1);
}
