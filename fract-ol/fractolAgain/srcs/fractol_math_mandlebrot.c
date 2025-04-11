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
/*   fractol_math_mandlebrot.c                     *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/09 11:16:56 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/09 11:16:56 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Calcule si un point (re,im) appartient à l'ensemble de Mandelbrot.
 * Pour Mandelbrot: z₀=0 et c=(re,im) dans l'équation z = z² + c.
 * Retourne le nombre d'itérations avant divergence.
 */

int	fractol_math_mandlebrot(double re, double im, int max_iter)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		iter;

	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	iter = 0;
	while (x2 + y2 <= 4 && iter < max_iter)
	{
		y = 2 * x * y + im;
		x = x2 - y2 + re;
		x2 = x * x;
		y2 = y * y;
		iter++;
	}
	return (iter);
}
