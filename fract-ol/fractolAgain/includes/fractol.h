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
/*   fractol.h                                     *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/03/22 15:45:31 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/03/22 15:45:31 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// libraries
# include "libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>

# define WIN_X 800
# define GOLDEN_RATIO 1.61803398875
# define WIN_Y (WIN_X / GOLDEN_RATIO)
# define MIN_RE -2
# define MAX_RE -MIN_RE / GOLDEN_RATIO
# define MIN_IM MIN_RE / 2
# define MAX_IM -MIN_RE / 2
# define ZOOM 4
# define MANDLEBROT 0

