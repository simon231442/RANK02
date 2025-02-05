/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:24:10 by ylabussi          #+#    #+#             */
/*   Updated: 2024/11/22 15:29:22 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char const **argv)
{
	t_settings	settings;
	t_cplx		anchor;
	double		scale;
	void		**win_meta;

	win_meta = malloc(sizeof(void *) * 5);
	if (!win_meta)
		return (1);
	settings = parse_input(argc, argv);
	win_meta[0] = mlx_init();
	win_meta[1] = mlx_new_window(win_meta[0], WIN_SIZE, WIN_SIZE, "fract-ol");
	scale = SCALE_INIT;
	anchor.re = ANCHOR_RE;
	anchor.im = ANCHOR_IM;
	win_meta[2] = &anchor;
	win_meta[3] = &scale;
	win_meta[4] = &settings;
	mlx_key_hook(win_meta[1], key_event, win_meta);
	mlx_mouse_hook(win_meta[1], on_mousedown, win_meta);
	mlx_hook(win_meta[1], DestroyNotify, 0, terminate, win_meta);
	render(win_meta);
	mlx_loop(win_meta[0]);
	return (0);
}

int	mandelbrot(t_cplx z, t_cplx c, int n)
{
	while (ftc_abs_sq(z) <= 4.0 && n > 0)
	{
		n--;
		z = ftc_add(ftc_mul(z, z), c);
	}
	return (n);
}

int	mandelbar(t_cplx z, t_cplx c, int n)
{
	while (ftc_abs_sq(z) <= 4.0 && n > 0)
	{
		n--;
		z = ftc_add(ftc_mul(ftc_conj(z), ftc_conj(z)), c);
	}
	return (n);
}
