/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucken <blucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:08:55 by blucken           #+#    #+#             */
/*   Updated: 2024/11/22 17:18:44 by blucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_color_fire(int iter, int max_iter, t_data *data)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (COLOR_BLACK);
	t = (double)iter / max_iter;
	r = (int)(MAX_COLOR_VALUE * pow(t, 1.5));
	g = (int)(MAX_COLOR_VALUE * pow(t, 3.0));
	b = (int)(MAX_COLOR_VALUE * pow(t, 4.5));
	r = (r * data->base_color.r) / MAX_COLOR_VALUE;
	g = (g * data->base_color.g) / MAX_COLOR_VALUE;
	b = (b * data->base_color.b) / MAX_COLOR_VALUE;
	limit_color_values(&r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}

void	limit_color_values(int *r, int *g, int *b)
{
	if (*r < 0)
		*r = 0;
	else if (*r > MAX_COLOR_VALUE)
		*r = MAX_COLOR_VALUE;
	if (*g < 0)
		*g = 0;
	else if (*g > MAX_COLOR_VALUE)
		*g = MAX_COLOR_VALUE;
	if (*b < 0)
		*b = 0;
	else if (*b > MAX_COLOR_VALUE)
		*b = MAX_COLOR_VALUE;
}

int	get_color_stripes(int iter, t_data *data)
{
	double	t;
	double	value;
	int		color;

	t = (double)iter / data->max_iter;
	value = 0.5 * sin(10.0 * t * M_PI) + 0.5;
	color = (int)(value * MAX_COLOR_VALUE);
	return ((color << 16) | (color << 8) | color);
}

int	get_color_smooth(int iter, t_data *data)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / data->max_iter;
	r = (int)(9 * (1 - t) * t * t * t * MAX_COLOR_VALUE);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * MAX_COLOR_VALUE);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * MAX_COLOR_VALUE);
	return ((r << 16) | (g << 8) | b);
}

int	get_color_classic(int iter, t_data *data)
{
	int	color;

	color = (iter * MAX_COLOR_VALUE / data->max_iter) % (MAX_COLOR_VALUE + 1);
	return ((color << 16) | (color << 8) | color);
}
