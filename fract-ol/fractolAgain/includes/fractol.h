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
# include <math.h>

# define WIN_X 800
# define GOLDEN_RATIO 1.61803398875
# define WIN_Y WIN_X / GOLDEN_RATIO
# define ZOOM 1.5
# define ITER_MAX 500

# define MANDLEBROT 0
# define JULIA 1
# define J_RE -0.7
# define J_IM 0.27015

# define NUM_THREADS 8

# define COLOR_DEFAULT 0x000000 // Black

//pour afficher les pixel
typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_data;

//pour exploiter les pixels calcule
typedef struct s_pixel_cache
{
	unsigned int	*calculated;
	int				iterations;
	double			*smoothed;
}	t_pixel_cache;

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
	int				show_ui;
}	t_env;

//main
void		fractol_env_init(t_env *env);
void		fractol_parsing(t_env *env, int ac, char **av);
int			fractol_mlx_start(t_env *env);
int			fractol_mlx_exit(t_env *env);
void		fractol_event(t_env *env);

//event
int			fractol_event_keyhook(int keycode, t_env *env);
int			fractol_event_zoom(int wheel, int x, int y, t_env *env);
//render
void		fractol_render(t_env *env);
int			fractol_render_loop(t_env *env);
void		fractol_pixel_draw(t_env *env, int x, int y);
int			fractol_pixel_color(t_env *env);
void		fractol_pixel_put(t_env *env, int x, int y, int color);
//math
int			fractol_math_mandlebrot(double re, double im, int max_iter);
int			fractol_math_julia(double re, double im, t_env *env);
int			fractol_math_color_bands(int iter, int max_iter);
int			fractol_math_color_fire(int iter, int max_iter);
int			fractol_math_color_gradient(int iter, int max_iter);
int			fractol_math_color_ocean(int iter, int max_iter);
int			fractol_math_color_psychedelic_1(int iter, int max_iter);
int			fractol_math_color_psychedelic_2(int iter, int max_iter);
int			fractol_math_color_rainbow(int iter, int max_iter);


//hook
# define LITTLECROSS 17
# define KEY_ESC 65307

#endif