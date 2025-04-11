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
/*   fractol_math_color_psychedelic_2.c            *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/09 20:43:13 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/09 20:43:13 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_math_color_psychedelic_2(int iter, int max_iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == max_iter)
		return (0x000000);
	r = (iter * 13) % 256;
	g = (iter * 7) % 256;
	b = (iter * 23) % 256;
	return (r << 16 | g << 8 | b);
}
