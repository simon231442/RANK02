/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:09:35 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/22 12:05:02 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_putnbr(long int n, int *len)
{
	int	digit;

	if (n == -2147483648)
	{
		*len += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		pf_putnbr(n / 10, len);
		pf_putnbr(n % 10, len);
	}
	if (n < 10)
	{
		digit = n + '0';
		*len += write(1, &digit, 1);
	}
	return ;
}

void	pf_putnbr_16(long int n, char speci, int *len)
{
	char	*set;

	if (speci == 'X')
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	if (n >= 16)
	{
		pf_putnbr_16(n / 16, speci, len);
		pf_putnbr_16(n % 16, speci, len);
	}
	if (n < 16)
		*len += write(1, &set[n], 1);
	return ;
}

void	pf_putptr_16(uintptr_t n, int *len)
{
	char	*x;

	x = "0123456789abcdef";
	if (n >= 16)
	{
		pf_putptr_16(n / 16, len);
		pf_putptr_16(n % 16, len);
	}
	if (n < 16)
		*len += write(1, &x[n], 1);
	return ;
}

void	pf_putptr(void *ptr, int *len)
{
	uintptr_t	p;

	p = (uintptr_t)ptr;
	if (IS_LINUX && p == 0)
	{
		*len += write(1, "(nil)", 5);
		return ;
	}
	*len += write(1, "0x", 2);
	pf_putptr_16(p, len);
	return ;
}
