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
t_env	*env_init(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->mlx = malloc(sizeof(t_vars));
	if (!env->mlx)
	{
		free(env);
		return (NULL);
	}
	env->img = malloc(sizeof(t_data));
	if (!env->img)
	{
		free(env->mlx);
		free(env);
		return (NULL);
	}
	env->nbc = malloc(sizeof(t_nbc));
	if (!env->nbc)
	{
		free(env->img);
		free(env->mlx);
		free(env);
		return (NULL);
	}
	env->nbc->min_re = MIN_RE;
	env->nbc->max_re = MAX_RE;
	env->nbc->min_im = MIN_IM;
	env->nbc->max_im = MAX_IM;
	env->nbc->max_iter = MAX_ITER;
	return (env);
}