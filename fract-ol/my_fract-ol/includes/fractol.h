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

# define WIN_X 2400
# define WIN_Y 1600
# define MIN_RE -2.5
# define MAX_RE 1.0
# define MIN_IM -1.5
# define MAX_IM 1.5
# define MAX_ITER 10

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
	t_vars	*mlx;
	t_data	*img;
	t_nbc	*nbc;
}	t_env;


t_env	*env_init(void);
int		event(int hook, void *env);
void	fractol_quit(t_env *env);
int 	close_window(void *param);

void	fractal_render(t_env *env);
int		mandlebrot(double x, double y);
int 	sierpinski(int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
