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

int	fractal_render(t_env *env)
{
	int x;
	int y;
	double a;
	double b;
	int color;

	y = WIN_Y;
	while (y >= 0)
	{
		x = 0;
		while (x < WIN_X)
		{
			a = env->nbc.min_re + x * (env->nbc.max_re - env->nbc.min_re) / WIN_X;
			b = env->nbc.min_im + y * (env->nbc.max_im - env->nbc.min_im) / WIN_Y;
			if (env->nbc.mandoujulia == MANDLEBROT)
				color = mandlebrot(a, b);
			else
				color = julia(a, b, env);
			my_mlx_pixel_put(&env->img, x, y, color);
			x++;
		}
		y--;
	}
	return(mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->img.img, 0, 0));
}
