/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:25:40 by ylabussi          #+#    #+#             */
/*   Updated: 2024/11/22 15:09:05 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_lerp(int c1, int c2, double t)
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	a = (c2 >> 24 % 256) + (double)(
			(unsigned char)(c1 >> 24 % 256)
			- (unsigned char)(c2 >> 24 % 256)) *t;
	r = (c2 >> 16 % 256) + (double)(
			(unsigned char)(c1 >> 16 % 256)
			- (unsigned char)(c2 >> 16 % 256)) *t;
	g = (c2 >> 8 % 256) + (double)(
			(unsigned char)(c1 >> 8 % 256)
			- (unsigned char)(c2 >> 8 % 256)) *t;
	b = (c2 >> 0 % 256) + (double)(
			(unsigned char)(c1 >> 0 % 256)
			- (unsigned char)(c2 >> 0 % 256)) *t;
	return ((a << 24) + (r << 16) + (g << 8) + (b << 0));
}

t_cplx	unit_dir(int key)
{
	if (key == UP_KEY)
		return (cplx_init(0.0, -1.0));
	if (key == DOWN_KEY)
		return (cplx_init(0.0, 1.0));
	if (key == RIGHT_KEY)
		return (cplx_init(1.0, 0.0));
	if (key == LEFT_KEY)
		return (cplx_init(-1.0, 0.0));
	else
		return (cplx_init(0.0, 0.0));
}

int	color_rule(t_cplx c, int depth, void **win_meta)
{
	int			d;
	double		t;
	t_cplx		s;
	t_settings	*settings;

	settings = win_meta[4];
	s = settings->seed;
	if (settings->type == 0)
		d = mandelbrot(s, c, depth);
	else if (settings->type == 1)
		d = mandelbrot(c, s, depth);
	else if (settings->type == 2)
		d = mandelbar(s, c, depth);
	t = (double) d / depth;
	if (d == 0)
		return (settings->color_in);
	else
		return (color_lerp(settings->color_out_1, settings->color_out_2, t));
}

t_cplx	true_pos(int x, int y, void **win_meta)
{
	t_cplx	r;
	t_cplx	*anchor;
	double	*scale;

	anchor = win_meta[2];
	scale = win_meta[3];
	r.re = anchor->re + *scale * x / WIN_SIZE;
	r.im = anchor->im + *scale * y / WIN_SIZE;
	return (r);
}
