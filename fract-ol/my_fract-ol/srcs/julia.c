/* ************************************************************************** */
/*                                                                            */
/*                                                           *                */
/*                                                          * *               */
/*   julia.c                                               *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/25 11:19:32 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/25 11:19:32 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(double a, double b, t_env *env)
{
    double  tmp;
    int     iter;

    iter = 0;
    while (a * a + b * b <= 4 && iter < MAX_ITER)
    {
        tmp = a * a - b * b + env->nbc.julia_re;
        b = 2 * a * b + env->nbc.julia_im;
        a = tmp;
        iter++;
    }
    if (iter == MAX_ITER)
        return 0x00000000; // Black
    return (fractol_color_gradient(iter)); // White
}