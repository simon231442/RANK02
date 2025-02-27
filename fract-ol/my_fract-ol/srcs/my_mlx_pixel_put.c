/* ************************************************************************** */
/*                                                                            */
/*                                                           *                */
/*                                                          * *               */
/*   my_mlx_pixel_put.c                                    *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 20:59:01 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/13 20:59:01 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
