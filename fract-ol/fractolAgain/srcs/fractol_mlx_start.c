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
/*   fractol_mlx_start.c                           *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/07 11:00:43 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/07 11:00:43 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_mlx_start(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed\n", 2);
		return (1);
	}
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "fract-ol");
	if (!env->win)
	{
		ft_putstr_fd("Error: mlx_new_window failed\n", 2);
		return (1);
	}
	env->img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	if (!env->img.img)
	{
		ft_putstr_fd("Error: mlx_new_image failed\n", 2);
		return (1);
	}	
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel,
			&env->img.line_length, &env->img.endian);
	return (0);
}
