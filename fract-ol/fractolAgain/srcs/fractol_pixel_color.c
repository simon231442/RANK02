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
/*   fractol_pixel_color.c                         *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/10 00:19:19 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/10 00:19:19 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Tableau de pointeurs de fonctions pour tous les schémas de couleur disponibles
** Chaque index (COLOR_GRADIENT, COLOR_RAINBOW, etc.) correspond à une fonction
*/

int	fractol_pixel_color(t_env *env)
{
	static int	(*g_color_functions[])(int, int) = {
		fractol_math_color_bands,
		fractol_math_color_fire,
		fractol_math_color_gradient,
		fractol_math_color_ocean,
		fractol_math_color_psychedelic_1,
		fractol_math_color_psychedelic_2,
		fractol_math_color_rainbow,
	};

	return (g_color_functions[env->color_sheme](env->cache.iterations,
		env->max_iter));
}
