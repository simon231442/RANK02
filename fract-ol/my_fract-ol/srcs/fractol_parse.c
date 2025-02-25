/* ************************************************************************** */
/*                                                                            */
/*                                                           *                */
/*                                                          * *               */
/*   fractol_parse.c                                       *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/25 12:03:49 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/25 12:03:49 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_parse(t_env *env, int ac, char **av)
{
	if (ac < 2 || ac > 4)
	{
		ft_putstr_fd("Usage: ./fractol [m/j] [re] [im]\n", 2);
		exit(1);
	}
	if(av[1][0] == 'm')
		env->nbc.mandoujulia = 0;
	else if(av[1][0] == 'j')
		env->nbc.mandoujulia = 1;
	if (ac == 4)
	{
		env->nbc.julia_re = ft_atoi(av[2]);
		env->nbc.julia_im = ft_atoi(av[3]);
	}
}