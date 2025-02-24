/* ************************************************************************** */
/*                                                                            */
/*                                                           *                */
/*                                                          * *               */
/*   fractol_zoom.c                                        *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/23 19:54:53 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/23 19:54:53 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_zoom(int wheel, int x, int y, t_env *env)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = env->nbc.min_re + (x * (env->nbc.max_re - env->nbc.min_re) / WIN_X);
	mouse_im = env->nbc.min_im + (y * (env->nbc.max_im - env->nbc.min_im) / WIN_Y);

	if (wheel == 4)
	{
		env->nbc.min_re = mouse_re + (env->nbc.max_re - env->nbc.min_re) / ZOOM / 2;
		env->nbc.max_re = mouse_re - (env->nbc.max_re - env->nbc.min_re) / ZOOM / 2;
		env->nbc.min_im = mouse_im + (env->nbc.max_im - env->nbc.min_im) / ZOOM / 2;
		env->nbc.max_im = mouse_im - (env->nbc.max_im - env->nbc.min_im) / ZOOM / 2;
	}
	if (wheel == 5)
	{
		env->nbc.min_re = mouse_re + (env->nbc.max_re - env->nbc.min_re) * ZOOM * 2;
		env->nbc.max_re = mouse_re - (env->nbc.max_re - env->nbc.min_re) * ZOOM * 2;
		env->nbc.min_im = mouse_im + (env->nbc.max_im - env->nbc.min_im) * ZOOM * 2;
		env->nbc.max_im = mouse_im - (env->nbc.max_im - env->nbc.min_im) * ZOOM * 2;
	}
	return (fractal_render(env));
}