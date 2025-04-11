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
/*   fractol_pixel_put.c                           *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/09 19:59:31 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/09 19:59:31 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** fractol_pixel_put: Place un pixel de couleur donnée dans l'image
** -----------------------------------------------------------------
** La couleur est stockée comme un int (32 bits ou 4 octets) mais nous devons
** la décomposer en 3 octets distincts (format RGB/BGR selon l'endianness):
**
** env->img.addr[i] = color;        // Octet 1 (Bleu dans format RGB)
** env->img.addr[i + 1] = color >> 8; // Octet 2 (Vert dans format RGB)
** env->img.addr[i + 2] = color >> 16; // Octet 3 (Rouge dans format RGB)
**
** Dans l'expression color >> N:
** - color est un entier 32 bits représentant la couleur complète
** - >> est l'opérateur de décalage à droite qui permet d'isoler chaque octet
** - La mémoire de l'image est un tableau de char (8 bits) où chaque pixel
**   occupe 3 ou 4 positions consécutives (selon le format de couleur)
*/

void	fractol_pixel_put(t_env *env, int x, int y, int color)
{
	int		i;

	i = (y * env->img.line_length + x * (env->img.bits_per_pixel / 8));
	env->img.addr[i] = color;
	env->img.addr[i + 1] = color >> 8;
	env->img.addr[i + 2] = color >> 16;
}
