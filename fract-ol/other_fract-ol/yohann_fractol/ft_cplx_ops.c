/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cplx_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:24:07 by ylabussi          #+#    #+#             */
/*   Updated: 2024/11/25 14:54:58 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cplx.h"

/**
 * @brief complex sum of a and b (a + b)
 * 
 * @param a 
 * @param b 
 * @return t_cplx 
 */
t_cplx	ftc_add(t_cplx a, t_cplx b)
{
	t_cplx	r;

	r.re = a.re + b.re;
	r.im = a.im + b.im;
	return (r);
}

/**
 * @brief complex difference of a and b (a - b)
 * 
 * @param a 
 * @param b 
 * @return t_cplx 
 */
t_cplx	ftc_sub(t_cplx a, t_cplx b)
{
	t_cplx	r;

	r.re = a.re - b.re;
	r.im = a.im - b.im;
	return (r);
}

/**
 * @brief complex product of a and b (a * b)
 * 
 * @param a 
 * @param b 
 * @return t_cplx 
 */
t_cplx	ftc_mul(t_cplx a, t_cplx b)
{
	t_cplx	r;

	r.re = a.re * b.re - a.im * b.im;
	r.im = a.re * b.im + a.im * b.re;
	return (r);
}

/**
 * @brief complex division of a by b (a / b)
 * 
 * @param a 
 * @param b 
 * @return t_cplx 
 */
t_cplx	ftc_div(t_cplx a, t_cplx b)
{
	t_cplx	r;

	r.re = (a.re * b.re + a.im * b.im) / b.re * b.re + b.im * b.im;
	r.im = (-a.re * b.im + a.im * b.re) / b.re * b.re + b.im * b.im;
	return (r);
}

/**
 * @brief scale a by s (a * s where s is a real number)
 * 
 * @param a 
 * @param s 
 * @return t_cplx 
 */
t_cplx	ftc_scale(t_cplx a, double s)
{
	t_cplx	r;

	r.re = a.re * s;
	r.im = a.im * s;
	return (r);
}
