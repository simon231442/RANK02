/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cplx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:24:03 by ylabussi          #+#    #+#             */
/*   Updated: 2024/11/25 14:31:02 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CPLX_H
# define FT_CPLX_H

/**
 * 
 * [wiki link]: https://en.wikipedia.org/wiki/Complex_number
 * 
 * represents a complex number
 * 
 * cplx.re = ℜ(z) - real part
 * cplx.im = ℑ(z) - imaginary part (factor of i)
 * 
 * more info: [wiki link]
 */
typedef struct cplx
{
	double	re;
	double	im;
}	t_cplx;

t_cplx	ftc_add(t_cplx a, t_cplx b);
t_cplx	ftc_sub(t_cplx a, t_cplx b);
t_cplx	ftc_mul(t_cplx a, t_cplx b);
t_cplx	ftc_div(t_cplx a, t_cplx b);
t_cplx	ftc_scale(t_cplx a, double b);

t_cplx	ftc_conj(t_cplx a);
t_cplx	cplx_init(double re, double im);
double	ftc_abs_sq(t_cplx a);

#endif