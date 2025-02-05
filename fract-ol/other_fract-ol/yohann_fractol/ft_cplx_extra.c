/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cplx_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:53:24 by ylabussi          #+#    #+#             */
/*   Updated: 2024/11/25 14:54:43 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cplx.h"

double	ftc_abs_sq(t_cplx a)
{
	return (a.re * a.re + a.im * a.im);
}

/**
 * @brief initialize a complex number from 2 reals
 * 
 * @param re 
 * @param im 
 * @return t_cplx 
 */
t_cplx	cplx_init(double re, double im)
{
	t_cplx	r;

	r.re = re;
	r.im = im;
	return (r);
}

/**
 * @brief complex conjugate of a (a̅)
 * 
 * @param a 
 * @return t_cplx 
 */
t_cplx	ftc_conj(t_cplx a)
{
	t_cplx	r;

	r.re = a.re;
	r.im = -a.im;
	return (r);
}
