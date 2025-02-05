/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:20:19 by ylabussi          #+#    #+#             */
/*   Updated: 2024/11/25 14:49:02 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(char *str)
{
	int	i;
	int	r;

	i = 0;
	i += (str[i] == '-');
	while ('0' <= str[i] && str[i] <= '9')
	{
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	double	r;
	int		i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	r = ft_atoi(str + i);
	while (r <= 1.0)
		r /= 10.0;
	r += ft_atoi(str);
	return (r);
}

t_cplx	ftc_atoc(char *str)
{
	int		i;
	t_cplx	r;

	r.re = atof(str);
	i = 1;
	while (('0' <= str[i] && str[i] <= '9') || str[i] == '.')
		i++;
	i += (str[i] == '+');
	r.im = atof(str + i);
	return (r);
}

unsigned int	hextoi(char const *str)
{
	unsigned int	r;
	int				i;
	char			*base;
	char			*digit;

	base = "0123456789ABCDEF";
	i = 0;
	r = 0;
	digit = ft_strchr(base, str[i]);
	while (0 <= (digit - base) && (digit - base) < 16)
	{
		r <<= 4;
		r += digit - base;
		i++;
		digit = ft_strchr(base, str[i]);
	}
	return (r);
}

char	*ft_strchr(char *str, int search_str)
{
	char	*ptr;
	size_t	i;

	if (!str)
		return (NULL);
	if ('a' <= search_str && search_str <= 'z')
		search_str -= 32;
	ptr = NULL;
	i = 0;
	while (str[i] && str[i] != search_str)
		i++;
	if (str[i] == search_str)
		ptr = &(str[i]);
	return (ptr);
}
