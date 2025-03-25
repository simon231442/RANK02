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
/*   fractol_anti_aliasing.c                       *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/03/23 18:26:38 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/03/23 18:26:38 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_anti_aliasing(t_data *img, t_neighbors *neighbors)
{
	int 			*src;
	char			*dst;
	int				x;
	int				y;
	int				i;
	int				pixel;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	src = malloc(sizeof(int) * WIN_X * WIN_Y);
	if (!src)
		return (1);
	ft_memcpy(src, img->addr, sizeof(int) * WIN_X * WIN_Y);
	dst = img->addr;
	y = 1;
	while (y < WIN_Y - 1)
	{
		x = 1;
		while (x < WIN_X - 1)
		{
			r = 0;
			g = 0;
			b = 0;
			i = 0;
			while (i < 9)
			{
				pixel = src[y * img->line_length + x *(img->bits_per_pixel / 8) + neighbors->offsets[i]];
				r += ((pixel >> 16) & 0xFF) * neighbors->weights[i];
				g += ((pixel >> 8) & 0xFF) * neighbors->weights[i];
				b += (pixel & 0xFF) * neighbors->weights[i];
				i++;
			}
			dst[y * img->line_length + x *(img->bits_per_pixel / 8)] = 0xFF000000 | ((r / neighbors->total_weight) << 16) |
				((g / neighbors->total_weight) << 8) |
				(b / neighbors->total_weight);
			x++;
		}
		y++;
	}
	free(src);
	return (0);
}
