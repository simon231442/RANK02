/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucken <blucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:47:40 by blucken           #+#    #+#             */
/*   Updated: 2024/11/21 13:50:46 by blucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calculate_coordinates(t_data *data, t_zoom *zoom)
{
	zoom->start_x = (zoom->x_start / (double)WIN_WIDTH - 0.5) * 4.0
		/ data->zoom + data->offset_x;
	zoom->start_y = (zoom->y_start / (double)WIN_HEIGHT - 0.5) * 4.0
		/ data->zoom + data->offset_y;
	zoom->end_x = (zoom->x_end / (double)WIN_WIDTH - 0.5) * 4.0
		/ data->zoom + data->offset_x;
	zoom->end_y = (zoom->y_end / (double)WIN_HEIGHT - 0.5) * 4.0
		/ data->zoom + data->offset_y;
}

void	update_zoom_and_center(t_data *data, t_zoom *zoom)
{
	t_zoom_calc	calc;

	calc.selected_width = fabs(zoom->end_x - zoom->start_x);
	calc.selected_height = fabs(zoom->end_y - zoom->start_y);
	calc.zoom_factor_x = 4.0 / (calc.selected_width * data->zoom);
	calc.zoom_factor_y = 4.0 / (calc.selected_height * data->zoom);
	if (calc.zoom_factor_x < calc.zoom_factor_y)
		data->zoom *= calc.zoom_factor_x;
	else
		data->zoom *= calc.zoom_factor_y;
	calc.new_center_x = zoom->start_x + calc.selected_width / 2.0;
	calc.new_center_y = zoom->start_y + calc.selected_height / 2.0;
	data->offset_x = calc.new_center_x;
	data->offset_y = calc.new_center_y;
}

void	update_zoom_and_offset(t_data *data, t_zoom zoom)
{
	double	new_width;
	double	new_height;
	double	zoom_ratio_x;
	double	zoom_ratio_y;
	double	new_zoom;

	new_width = zoom.x_max - zoom.x_min;
	new_height = zoom.y_max - zoom.y_min;
	zoom_ratio_x = WIN_WIDTH / new_width;
	zoom_ratio_y = WIN_HEIGHT / new_height;
	new_zoom = fmin(zoom_ratio_x, zoom_ratio_y);
	data->zoom *= new_zoom;
	data->offset_x = (zoom.x_min + zoom.x_max) / 2.0;
	data->offset_y = (zoom.y_min + zoom.y_max) / 2.0;
}

char	*join_and_free(char *int_str, char *frac_str)
{
	char	*result;

	result = ft_strjoin(int_str, frac_str);
	free(int_str);
	free(frac_str);
	return (result);
}

int	handle_allocation(char **int_str, char **frac_str,
	long long int_part, int precision)
{
	*int_str = ft_lltoa(int_part, 0);
	if (!(*int_str))
		return (0);
	*frac_str = (char *)malloc(precision + 2);
	if (!(*frac_str))
	{
		free(*int_str);
		return (0);
	}
	return (1);
}
