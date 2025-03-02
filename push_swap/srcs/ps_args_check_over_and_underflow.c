/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_check_over_and_underflow.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:15:03 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/27 23:15:03 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ps_atol(char *str);

void    ps_args_check_over_and_underflow(char **self)
{
	int 	i;
	long	nb;

	i = 0;
	while (self[i])
	{
		nb = ps_atol(self[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ps_error(self);
		i++;
	}
}

static long	ps_atol(char *str)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}