/* ************************************************************************** */
/*                                                           *                */
/*                                                          * *               */
/*   fractol_quit.c                                        *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 14:34:50 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/13 14:34:50 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_quit(t_env *env)
{
	mlx_destroy_window(env->mlx.mlx, env->mlx.win);
	mlx_destroy_display(env->mlx.mlx);
	exit(0);
}
