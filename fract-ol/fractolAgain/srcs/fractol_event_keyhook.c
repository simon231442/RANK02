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
/*   fractol_event_keyhook.c                       *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/10 01:02:23 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/10 01:02:23 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	fractol_event_keyhook(int keycode, t_env *env)
{
	if (keycode >= 49 && keycode <= 55)
	{
		env->color_sheme = keycode - 49;
		env->view.needs_redraw = 1;
	}
	if (keycode == KEY_ESC)
	{
		fractol_mlx_exit(env);
	}
	fractol_render(env);
	return (0);
}
