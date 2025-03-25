/* ************************************************************************** */
/*                                                           *                */
/*                                                          * *               */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 14:29:55 by srenaud           *   *   *   *          */
/*   Updated: 2025/03/24 13:35:10 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// libraries
# include "libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <math.h>

# define WIN_X 1500 
# define GOLDEN_RATIO 1.61803398875
# define WIN_Y (WIN_X / GOLDEN_RATIO)
# define MIN_RE -2
# define MAX_RE -MIN_RE / GOLDEN_RATIO
# define MIN_IM MIN_RE / 2
# define MAX_IM -MIN_RE / 2
# define ZOOM 4
# define MANDLEBROT 0

# define MAX_ITER 500

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
	int		mandoujulia;
	double 	julia_re;
	double 	julia_im;
}	t_nbc;

typedef struct s_neighbors
{
	int			offsets[9];
	int			weights[9];
	int			total_weight;
}	t_neighbors;

typedef struct s_env
{
	t_vars	mlx;
	t_data	img;
	t_nbc	nbc;
	t_neighbors	neighbors;
}	t_env;

void	env_init(t_env *env);
int		event(int hook, void *env);
void	fractol_quit(t_env *env);
int 	close_window(void *param);

void	fractol_parse(t_env *env, int ac, char **av);
int		fractal_render(t_env *env);
int		mandlebrot(double x, double y);
int		julia(double x, double y, t_env *env);
int		fractol_color_gradient(int iter);
void	fractol_anti_aliasing_neighbors_init(t_data *data, t_neighbors *nb);
int		fractol_anti_aliasing(t_data *img, t_neighbors *neighbors);
double	fractol_mandelbrot_iter_smooth(double iter);
int 	sierpinski(int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		fractol_zoom(int wheel, int x, int y, t_env *env);

//test
int    test_render(t_env *env);
#endif
