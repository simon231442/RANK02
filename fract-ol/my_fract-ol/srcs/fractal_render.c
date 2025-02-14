/* ************************************************************************** */
/*                                                                            */
/*                                                           *                */
/*                                                          * *               */
/*   fractal_render.c                                      *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 21:05:29 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/13 21:05:29 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_render(t_env *env)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		color;
	int		iterations;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			real = (x - WIN_X / 2.0) * 4.0 / WIN_X;
			imag = (y - WIN_Y / 2.0) * 4.0 / WIN_Y;
			iterations = mandelbrot(real, imag);
			color = (iterations == 1000) ? 0x000000 : 0xFFFFFF;
			my_mlx_pixel_put(env->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->win, env->img->img, 0, 0);
}