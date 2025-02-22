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
	int x;
	int y;
	double a;
	double b;
	int color;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			a = env->nbc->min_re + x * (env->nbc->max_re - env->nbc->min_re) / WIN_X;
			b = env->nbc->min_im + y * (env->nbc->max_im - env->nbc->min_im) / WIN_Y;
			color = mandlebrot(a, b);
			my_mlx_pixel_put(env->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->win, env->img->img, 0, 0);
}
