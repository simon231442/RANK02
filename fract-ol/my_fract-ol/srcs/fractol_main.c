/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:29:54 by srenaud           #+#    #+#             */
/*   Updated: 2025/02/10 13:29:54 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main()
{
		t_env		env;

		env.mlx.mlx = mlx_init();
		env.mlx.win = mlx_new_window(env.mlx.mlx, WIN_X, WIN_Y, "fract-ol");
		mlx_key_hook(env.mlx.win, event, &env);
		mlx_hook(env.mlx.win, 17, 0, event, &env);
		mlx_loop(env.mlx.mlx);
		return (0);
}