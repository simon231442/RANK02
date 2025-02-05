/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:06:52 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/15 21:58:09 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}*/
void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char	bit;

	i = 8;
	while (i > 0)
	{
		i--;
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int	main(void)
{
	unsigned char	octet;

	octet = 143;
	print_bits(octet);
	return (0);
}
