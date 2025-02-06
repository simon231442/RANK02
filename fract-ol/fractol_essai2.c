/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:22:25 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/05 16:59:05 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}
void	draw_square(t_data *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (i < size)
	{
		while (j < size)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

int	close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
    if (keycode == 65307) // ESC key
        close_window(vars);
    return (0);
}

int main(void)
{
	t_vars	win;
	t_data	img;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1920, 1080, "test");
	img.img = mlx_new_image(win.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_square(&img, 500, 200, 750, 0x00FF0000);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_hook(win.win, 17, 0, close_window, &win);
    mlx_key_hook(win.win, key_hook, &win);
	mlx_loop(win.mlx);
}