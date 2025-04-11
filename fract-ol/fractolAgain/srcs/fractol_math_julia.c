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
/*   fractol_math_julia.c                          *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/09 11:46:49 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/09 11:46:49 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Calcule si un point (re,im) appartient à l'ensemble de Julia.
 * Pour Julia:	-on commence avec les coordonnées du point
 * 				-z₀=(re,im) et c=(julia_re,julia_im) dans z = z² + c.
 * Retourne le nombre d'itérations avant divergence.
 */

int	fractol_math_julia(double re, double im, t_env *env)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		iter;

	x = re;
	y = im;
	x2 = x * x;
	y2 = y * y;
	iter = 0;
	while (x2 + y2 <= 4 && iter < env->max_iter)
	{
		y = 2 * x * y + env->julia_params[1];
		x = x2 - y2 + env->julia_params[0];
		x2 = x * x;
		y2 = y * y;
		iter++;
	}
	return (iter);
}
