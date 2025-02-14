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

int	mandelbrot(double real, double imag)
{
	double	z_real;
	double	z_imag;
	int		iterations;
	int		max_iterations;
	double	temp_real;
	double	magnitude_squared;

	z_real = 0;
	z_imag = 0;
	iterations = 0;
	max_iterations = 1000;
	magnitude_squared = z_real * z_real + z_imag * z_imag;
	while (magnitude_squared <= 4 && iterations < max_iterations)
	{
		temp_real = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = temp_real;
		iterations++;
	}
	return (iterations);
}
