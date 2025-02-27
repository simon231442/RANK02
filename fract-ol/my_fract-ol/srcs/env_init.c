/* ************************************************************************** */
/*                                                           *                */
/*                                                          * *               */
/*   srcs/env_init.c                                       *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 16:20:00 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/13 16:20:00 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	env_init(t_env *env)
{
	env->mlx.mlx = NULL;
	env->mlx.win = NULL;
	env->img.img = NULL;
	env->img.addr = NULL;
	env->nbc.min_re = MIN_RE;
	env->nbc.max_re = MAX_RE;
	env->nbc.min_im = MIN_IM;
	env->nbc.max_im = MAX_IM;
	env->nbc.max_iter = MAX_ITER;
}