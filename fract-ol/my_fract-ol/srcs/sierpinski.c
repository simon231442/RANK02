/* ************************************************************************** */
/*                                                                            */
/*                                                           *                */
/*                                                          * *               */
/*   sierpinski.c                                          *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/20 12:16:02 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/20 12:16:02 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int sierpinski(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 2 == 1 && y % 2 == 1)
			return 0x00000000; // Black
		x /= 2;
		y /= 2;
	}
	return 0x00FFFFFF; // White
}