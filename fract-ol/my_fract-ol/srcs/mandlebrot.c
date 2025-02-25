/* ************************************************************************** */
/*                                                                            */
/*                                                           *                */
/*                                                          * *               */
/*   mandelbrot.c                                          *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 20:37:28 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/13 20:37:28 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandlebrot(double a, double b)
{
	double	x;
	double	y;
	double	tmp;
	int		iter;

	x = 0;
	y = 0;
	iter = 0;
	while (x * x + y * y <= 4 && iter < MAX_ITER)
	{
		tmp = x * x - y * y + a;
		y = 2 * x * y + b;
		x = tmp;
		iter++;
	}
	if (iter == MAX_ITER)
			return 0x00000000; // Black

    return 0xFFFFFF; // White
}
