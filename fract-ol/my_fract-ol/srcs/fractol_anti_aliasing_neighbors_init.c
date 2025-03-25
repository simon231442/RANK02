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
/*   fractol_anti_aliasing_neighbors_init.c        *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/03/23 13:20:13 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/03/23 13:20:13 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_anti_aliasing_neighbors_init(t_data *data, t_neighbors *nb)
{
	int			x;	
	int			y;
	int			i;
	static int	weights[9] = {1, 2, 1,
		2, 4, 2,
		1, 2, 1};

	y = -1;
	i = 0;
	while (y <= 1)
	{
		x = -1;
		while (x <= 1)
		{
			nb->offsets[i] = y * data->line_length + x * (data->bits_per_pixel / 8);
			nb->weights[i] = weights[i];
			nb->total_weight += weights[i];
			x++;
			i++;
		}
		y++;
	}
}
