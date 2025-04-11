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
/*   fractol_pixel_draw.c                          *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/09 19:52:53 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/09 19:52:53 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	fractol_pixel_draw(t_env *env, int x, int y)
{
	double	re;
	double	im;
	int		color;

	re = env->view.center_re + ((double)x - WIN_X / 2) * env->view.scale;
	im = env->view.center_im + ((double)y - WIN_Y / 2) * env->view.scale;
	if (env->fractal_type == MANDLEBROT)
		env->cache.iterations = fractol_math_mandlebrot(re, im, env->max_iter);
	else if (env->fractal_type == JULIA)
		env->cache.iterations = fractol_math_julia(re, im, env);
	color = fractol_pixel_color(env);
	fractol_pixel_put(env, x, y, color);
}
