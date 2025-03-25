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
/*   test_render.c                                 *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/03/24 11:38:53 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/03/24 11:38:53 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	test_render(t_env *env)
{
	int x;
	int y;
	int color;

	y = WIN_Y;
	while (y >= 0)
	{
		x = 0;
		while (x < WIN_X)
		{
			color = 0x00ffff00;
			my_mlx_pixel_put(&env->img, x, y, color);
			x++;
		}
		y--;
	}
	return(mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->img.img, 0, 0));
}
