/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:26 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/15 19:00:26 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_in_bulb(double x, double y) 					// check if the point is in the bulb. the bulb is a circle with a radius of 1/4
{
	double	p; 												// distance from the point to the center of the bulb
	double	q;												// distance from the point to the center of the main cardioid
															// the main cardioid is a circle with a radius of 1/2

	p = sqrt(((x - 0.25) * (x - 0.25)) + (y * y));			// calculate the distance from the point to the center of the bulb
	q = p - (2 * (p * p)) + 0.25;				// calculate the distance from the point to the center of the main cardioid		
	if (x < q)											// if the point is inside the bulb		
		return (1);
	if ((((x + 1) * (x + 1) + y * y)) < (1.0 / 16.0)) 			// if the point is inside the smaller bulb
		return (1);
	return (0);
}

static void	calculate_iterator(t_m_struct *data, t_complex *z)
{
	t_fractal	*f;

	f = &data->f;
	if (f->fractal_type == 2 && is_in_bulb(z->real, z->im))  // if the point is in the bulb, set the iterator to the maximum number of iterations
	{
		f->iter = MAX_ITER;
		f->magnitude = 0.0;
		return ;
	}
	f->magnitude = 0.0;
	f->iter = 0;
	f->z = *z;
	while (f->iter < MAX_ITER && (f->magnitude < 4))
	{
		f->iteration_f(data, &(f->z), z);
		f->magnitude = (f->z.real * f->z.real) + (f->z.im * f->z.im);
		f->iter++;
	}
	if (f->iter < MAX_ITER)
		f->smooth_iter = f->iter + 1.0 - log(log(f->magnitude)) / log(2.0);
	else
		f->smooth_iter = data->f.iter;
}

void	set_color(t_m_struct *data, t_complex *z)
{
	calculate_iterator(data, z);
	set_gradient(data);
}

int	render(t_m_struct *data) 					// render the fractal, render means to draw the fractal
{
	if (!data->request_render)					// if the render is not requested, return 0
		return (0);
	data->request_render = 0;
	view_draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->image.data, 0, 0);
	return (1);
}
