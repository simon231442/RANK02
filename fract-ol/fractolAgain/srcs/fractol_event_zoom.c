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
/*   fractol_event_zoom.c                          *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/09 13:33:51 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/09 13:33:51 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	fractol_event_zoom(int wheel, int x, int y, t_env *env)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = env->view.center_re + ((double)x - WIN_X / 2) * env->view.scale;
	mouse_im = env->view.center_im + ((double)y - WIN_Y / 2) * env->view.scale;
	env->view.last_mouse_x = x;
	env->view.last_mouse_y = y;
	if (wheel == 4)
		env->view.scale /= ZOOM;
	else if (wheel == 5)
		env->view.scale *= ZOOM;
	env->view.center_re = mouse_re - ((double)x - WIN_X / 2) * env->view.scale;
	env->view.center_im = mouse_im - ((double)y - WIN_Y / 2) * env->view.scale;
	//env->view.needs_redraw = 1;
	fractol_render(env);
	return (0);
}
