/* ************************************************************************** */
/*                                                           *                */
/*                                                          * *               */
/*   ../includes/fractol.h                                 *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 14:29:55 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/13 14:29:55 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// libraries
# include "libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>

# define WIN_X 800
# define GOLDEN_RATIO 1.61803398875
# define WIN_Y (WIN_X / GOLDEN_RATIO)
# define MIN_RE -2
# define MAX_RE -MIN_RE / GOLDEN_RATIO
# define MIN_IM MIN_RE / 2
# define MAX_IM -MIN_RE / 2
# define ZOOM 2

# define MAX_ITER 100

# define ESC_KEY 0xFF1B

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_nbc
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	int		max_iter;
}	t_nbc;

typedef struct s_env
{
	t_vars	mlx;
	t_data	img;
	t_nbc	nbc;
}	t_env;


void	env_init(t_env *env);
int		event(int hook, void *env);
void	fractol_quit(t_env *env);
int 	close_window(void *param);

int		fractal_render(t_env *env);
int		mandlebrot(double x, double y);
int 	sierpinski(int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		fractol_zoom(int wheel, int x, int y, t_env *env);
#endif
