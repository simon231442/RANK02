/* ************************************************************************** */
/*                                                           *                */
/*                                                          * *               */
/*   event.c                                               *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 14:27:11 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/13 14:27:11 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//renomer
int close_window(void *param)
{
    fractol_quit((t_env *)param);
    return (0);
}
//modifier renomer
int	event(int hook, void *env)
{
	if (hook == ESC_KEY)
		fractol_quit((t_env *)env);
	return (0);
}
