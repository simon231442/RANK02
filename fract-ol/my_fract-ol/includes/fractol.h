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
# define WIN_Y 800

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

typedef struct s_env
{
	t_vars	*mlx;
	t_data	*img;
}	t_env;

/*
** Create a new window.
**
** @param	void *mlx_ptr	the mlx instance pointer;
** @param	int  size_x		the width of the window;
** @param	int  size_y		the height of the window;
** @param	char *title		the title of the window;
** @return	void*			the window instance pointer.
*/
t_env	*env_init(void);
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int		event(int hook, void *env);
void	fractol_quit(t_env *env);

void	fractal_render(t_env *env);
int		mandelbrot(double real, double imag);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
