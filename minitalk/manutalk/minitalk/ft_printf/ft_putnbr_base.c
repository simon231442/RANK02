/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelmartin <manuelmartin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 00:05:19 by manuelma          #+#    #+#             */
/*   Updated: 2025/01/29 18:27:04 by manuelmarti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	recursive_print(unsigned long long int nbr, char *base)
{
	char	print;
	size_t	reste;
	int		i;

	i = 0;
	print = base[nbr % ft_strlen_printf(base)];
	reste = nbr / ft_strlen_printf(base);
	if (reste > 0)
		i += recursive_print(reste, base);
	write(1, &print, 1);
	i++;
	return (i);
}

int	ft_putnbr_base(long long int nbr, char *base)
{
	int	print_len;

	print_len = 0;
	if (nbr < 0)
	{
		print_len += write(1, "-", 1);
		print_len += recursive_print(-nbr, base);
	}
	else
		print_len += recursive_print(nbr, base);
	return (print_len);
}
