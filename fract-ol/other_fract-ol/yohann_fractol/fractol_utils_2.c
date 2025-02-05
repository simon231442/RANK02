/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:21:19 by ylabussi          #+#    #+#             */
/*   Updated: 2024/11/22 16:43:28 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render(void **win_meta)
{
	unsigned int	pos;
	int				color;
	void			*mlx;
	void			*img;
	double			*scale;

	mlx = win_meta[0];
	scale = win_meta[3];
	img = mlx_new_image(mlx, WIN_SIZE, WIN_SIZE);
	pos = 0;
	while (pos < WIN_SIZE * WIN_SIZE)
	{
		color = color_rule(
				true_pos(pos % WIN_SIZE, pos / WIN_SIZE, win_meta),
				log(2.0 / *scale) * 5 + 30,
				win_meta);
		pixel_put_image(win_meta, img, pos * 4, color);
		pos++;
	}
	mlx_put_image_to_window(mlx, win_meta[1], img, 0, 0);
	mlx_destroy_image(mlx, img);
	return (0);
}

int	key_event(int key, void **win_meta)
{
	t_cplx	*anchor;
	double	*scale;

	anchor = win_meta[2];
	scale = win_meta[3];
	if (key == ESC_KEY)
		terminate(win_meta);
	else if (LEFT_KEY <= key && key <= DOWN_KEY)
		*anchor = ftc_add(*anchor, ftc_scale(unit_dir(key), *scale / 6.0));
	else
		return (0);
	render(win_meta);
	return (0);
}

int	on_mousedown(int button, int x, int y, void **win_meta)
{
	t_cplx	*anchor;
	double	*scale;

	anchor = win_meta[2];
	scale = win_meta[3];
	if (button == 4 && *scale > 0.000000000001)
	{
		*anchor = ftc_add(ftc_scale(*anchor, SCALE_FACTOR_IN),
				ftc_scale(true_pos(x, y, win_meta), 1.0 - SCALE_FACTOR_IN));
		*scale = *scale * SCALE_FACTOR_IN;
	}
	else if (button == 5 && *scale < 10.0)
	{
		*anchor = ftc_add(ftc_scale(*anchor, SCALE_FACTOR_OUT),
				ftc_scale(true_pos(x, y, win_meta), 1.0 - SCALE_FACTOR_OUT));
		*scale = *scale * SCALE_FACTOR_OUT;
	}
	else
		return (0);
	render(win_meta);
	return (0);
}

int	pixel_put_image(void **win_meta, void *image, int pixel, int color)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	void	*mlx;

	mlx = win_meta[0];
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	if (pixel_bits != 32)
		color = mlx_get_color_value(mlx, color);
	if (endian)
	{
		buffer[pixel + 0] = (color >> 24);
		buffer[pixel + 1] = (color >> 16) & 0xFF;
		buffer[pixel + 2] = (color >> 8) & 0xFF;
		buffer[pixel + 3] = (color) & 0xFF;
	}
	else
	{
		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
	}
	return (0);
}

int	terminate(void **win_meta)
{
	void	*mlx;
	void	*win;

	mlx = win_meta[0];
	win = win_meta[1];
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	free(win_meta);
	exit(0);
	return (0);
}
