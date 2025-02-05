/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:03:01 by ylabussi          #+#    #+#             */
/*   Updated: 2024/11/25 14:52:09 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <mlx_int.h>
# include <math.h>
# include "ft_cplx.h"

# define SCALE_INIT 6.0
# define SCALE_FACTOR_IN 0.8
# define SCALE_FACTOR_OUT 1.25

# define ESC_KEY 0xFF1B
# define LEFT_KEY 0xFF51
# define UP_KEY 0xFF52
# define RIGHT_KEY 0xFF53
# define DOWN_KEY 0xFF54

# define WIN_SIZE 1024
# define ANCHOR_RE -3.0
# define ANCHOR_IM -3.0

# define TYPE 0
# define COLOR_IN 0xFF000000
# define COLOR_OUT_1 0xFF2E2D88
# define COLOR_OUT_2 0xFFB8860B

typedef struct settings
{
	t_cplx	seed;
	int		type;
	int		color_in;
	int		color_out_1;
	int		color_out_2;
}	t_settings;

// utils 1
int				color_lerp(int c1, int c2, double t);
int				color_rule(t_cplx c, int depth, void **win_meta);
t_cplx			true_pos(int x, int y, void **win_meta);

// utils 2
t_cplx			unit_dir(int key);
int				key_event(int key, void **win_meta);
int				pixel_put_image(
					void **win_meta, void *image, int pixel, int color);
int				terminate(void **win_meta);
int				render(void **win_meta);

// utils 3
int				ft_atoi(char *str);
double			ft_atof(char *str);
t_cplx			ftc_atoc(char *str);
unsigned int	hextoi(char const *str);
char			*ft_strchr(char *str, int search_str);

// main
int				on_mousedown(int button, int x, int y, void **win_meta);
int				main(int argc, char const **argv);
int				mandelbrot(t_cplx z, t_cplx c, int n);
int				mandelbar(t_cplx z, t_cplx c, int n);

// parsing
t_settings		parse_input(int argc, char const **argv);

#endif