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
	env->img.bits_per_pixel = 0;
	env->img.line_length = 0;
	env->img.endian = 0;
	env->img.center_re = 0;
	env->img.center_im = 0;
	env->img.scale = 0.004;
	env->img.last_mouse_x = 0;
	env->img.last_mouse_y = 0;
	env->img.needs_redraw = 0;
	env->fracal_type = 0;
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
