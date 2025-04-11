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
/*   fractol_math_color_bands.c                    *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/09 20:31:49 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/09 20:31:49 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_math_color_bands(int iter, int max_iter)
{
	static int	colors[16] = {
		0x421E0F, 0x19071A, 0x09012F, 0x040449,
		0x000764, 0x0C2C8A, 0x1852B1, 0x397DD1,
		0x86B5E5, 0xD3ECF8, 0xF1E9BF, 0xF8C95F,
		0xFFAA00, 0xCC8000, 0x995700, 0x6A3403
	};

	if (iter == max_iter)
		return (0x000000);
	return (colors[iter % 16]);
}
