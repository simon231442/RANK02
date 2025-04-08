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
/*   fractol_mlx_exit.c                            *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/08 12:33:13 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/08 12:33:13 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_mlx_exit(t_env *env)
{
	if (env->img.img)
		mlx_destroy_image(env->mlx.mlx, env->img.img);
	if (env->mlx.win)
		mlx_destroy_window(env->mlx.mlx, env->mlx.win);
	if (env->mlx.mlx)
		mlx_destroy_display(env->mlx.mlx);
}
