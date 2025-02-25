/* ************************************************************************** */
/*                                                                            */
/*                                                           *                */
/*                                                          * *               */
/*   fractol_color_gradient.c                              *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/25 13:20:48 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/25 13:20:48 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_color_gradient(int iter)
{
    int		red;
    int		green;
    int		blue;
    double	t;

    t = (double)iter / MAX_ITER;
    red = (int)(9 * (1 - t) * t * t * t * 255);
    green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (red << 16 | green << 8 | blue);
}