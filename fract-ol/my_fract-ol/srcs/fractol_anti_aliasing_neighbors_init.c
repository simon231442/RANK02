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
	int			dx;	
	int			dy;
	int			i;
	static int	weights[9] = {1, 2, 1,
		2, 4, 2,
		1, 2, 1};

	nb->total_weight = 0;
	dy = -1;
	i = 0;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			nb->offsets[i] = dy * data->line_length / (data->bits_per_pixel/8) + dx;
			nb->weights[i] = weights[i];
			nb->total_weight += weights[i];
			dx++;
			i++;
		}
		dy++;
	}
	i = 0;
	while (i < 9)
	{
		ft_printf("offsets[%d] = %d\n", i, nb->offsets[i]);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		ft_printf("weights[%d] = %d\n", i, nb->weights[i]);
		i++;
	}
	ft_printf("Total weight: %d\n", nb->total_weight);
}
