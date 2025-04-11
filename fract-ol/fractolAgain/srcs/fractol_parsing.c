/* ************************************************************************** */
/*   .         '            .                                                 */
/*        *          .       .     '           +           .        '         */
/*       .       *       '                .     .      .       +         .    */
/*   .      *                *      +                              .          */
/*         .                .                 .                         '     */
/*    '            '    .         .     '             +      *                */
/*     .          42, vers le cursus et au-dela         .   * *    .      '   */
/*               .                                '        *   *              */
/* *   '*             +      '    .                       * * * *      .      */
/*         *                .              .             *       *          . */
/*              *                       '       .       * *     * *    '      */
/*   .                  *      '   .                   *   *   *   *     '    */
/*      .      *             .            .           * * * * * * * *      .  */
/*                    *            .    .            *               *   .    */
/*                                                  * *             * *       */
/*   fractol_parsing.c                             *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/07 10:35:49 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/07 10:35:49 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_parsing(t_env *env, int ac, char **av)
{
	if (ac < 2 || ac > 4)
	{
		ft_putstr_fd("Usage: ./fractol [m/j] [re] [im]\n", 2);
		exit(1);
	}
	else if (av[1][0] == 'm')
		env->fractal_type = 0;
	else if (av[1][0] == 'j')
	{
		env->fractal_type = 1;
		if (ac == 4)
		{
			env->julia_params[0] = ft_atof(av[2]);
			env->julia_params[1] = ft_atof(av[3]);
		}
	}
}
