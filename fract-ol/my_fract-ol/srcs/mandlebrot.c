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
	double		tmp_real;
	double		tmp_imag;
	int			i;
	int			max_iter;

	i = 0;
	max_iter = 100;
	while (a * a + b * b <= 4)
	{
		tmp_real = a;
		tmp_imag = b;
		a = tmp_real * tmp_real - tmp_imag * tmp_imag + tmp_real;
		b = 2 * tmp_real * tmp_imag + tmp_imag;
		i++;
		if (i > max_iter)
			return (0x00000000); // Black
	}
	return (0x00FFFFFF); // White
}
