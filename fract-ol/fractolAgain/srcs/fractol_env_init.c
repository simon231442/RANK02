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
/*   fractol_env_init.c                            *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/08 10:25:30 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/08 10:25:30 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_env_init(t_env *env)
{
	env->mlx = NULL;
	env->win = NULL;
	env->img.img = NULL;
	env->img.addr = NULL;
	env->img.bits_per_pixel = 0;uedraw = 0;
	env->fractal_type = 0;
	env->julia_params[0] = J_RE;
	env->julia_params[1] = J_IM;
	env->max_iter = MAX_ITER;
	env->color_sheme = 0;
	env->anti_aliasing = 0;
	env->cache.calculated = NULL;
	env->cache.iteratioins = 0;
	env->cache.smoothed = NULL;
	env->show_ui = 1;
}
