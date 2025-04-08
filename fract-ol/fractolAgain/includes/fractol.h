/* ************************************************************************** */
/*   .         '            .                                                 */
/*        *          .       .     '           +           .        '         */
/*       .       *       '                .     .      .       +         .    */
/*   .      *                *      +                              .          */
/*         .                .                 .                         '     */
/*    '            '    .         .     '             +      *                */
/*     .          42, vers le cursus et au-dela         .   * *    .      '   */
/*               .                                '        *   *              */
/* *   '*             +      '    .                       * * * *      .      */
/*         *                .              .             *       *          . */
/*              *                       '       .       * *     * *    '      */
/*   .                  *      '   .                   *   *   *   *     '    */
/*      .      *             .            .           * * * * * * * *      .  */
/*                    *            .    .            *               *   .    */
/*                                                  * *             * *       */
/*   fractol.h                                     *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/03/22 15:45:31 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/03/22 15:45:31 by srenaud  * * * * * * * * * * * * * * * * */
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
# define WIN_Y WIN_X / GOLDEN_RATIO
# define ZOOM 1.5
# define MAX_ITER 100

# define MANDLEBROT 0
# define JULIA 1
# define J_RE -0.7
# define J_IM 0.27015

//pour exploiter les pixels calcule
typedef struct s_pixel_cache
{
	unsigned int	*calculated;
	int				iteratioins;
	double			*smoothed;
}	t_pixel_cache;

//pour le threading
typedef struct s_thread_data
{
	pthread			thread;
	int				id;
	int				start_y;
	int				end_y;
	t_env			*env;
}	t_thread_data;

//pour la vue, zoom
typedef struct s_view
{
	double			center_re;
	double			center_im;
	double			scale;
	double			last_mouse_x;
	double			last_mouse_y;
	int				needs_redraw;
}	t_view;

//principale 
typedef struct s_env
{
	void			*mlx;
	void			*win;
	t_data			img;
	t_view			view;
	int				fractal_type;
	double			julia_params[2];
	int				max_iter;
	int				color_sheme;
	int				anti_aliasing;
	t_pixel_cache	cache;
	t_thread_data	threads[NUM_THREADS];
	int				show_ui;
}	t_env;

//pour afficher les pixel
typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_data;

//main
void		fractol_env_init(t_env *env);
void		fractol_parsing(t_env *env, int ac, char **av);
void		fractol_mlx_start(t_env *env);
void		fractol_mlx_exit(t_env *env);
