/* ************************************************************************** */
/*                                                           *                */
/*                                                          * *               */
/*   fractol_main.c                                        *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 14:25:39 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/13 14:25:39 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_env *env;

	env = env_init();
	env->mlx->mlx = mlx_init();
	env->mlx->win = mlx_new_window(env->mlx->mlx, WIN_X, WIN_Y, "fract-ol");
	env->img->img = mlx_new_image(env->mlx->mlx, WIN_X, WIN_Y);
	env->img->addr = mlx_get_data_addr(env->img->img, &env->img->bits_per_pixel,
		&env->img->line_length, &env->img->endian);
	fractal_render(env);
	mlx_key_hook(env->mlx->win, event, env);
	mlx_hook(env->mlx->win, DestroyNotify, 0, event, env);
	mlx_loop(env->mlx->mlx);
	return (0);
}