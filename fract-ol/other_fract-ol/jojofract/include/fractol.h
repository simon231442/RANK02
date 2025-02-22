/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:31:28 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/21 12:25:48 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include <math.h>
# include <time.h>



# ifdef __APPLE__ // if it detects we are on mac
# include <mlx.h>
# define WIN_WIDTH 800
# define WIN_HEIGHT 800 //to do: check why this does not update
# define SCALE 4

enum // events for macos 
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
enum // mouse clicks for macos 
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_BACKWARD = 4,
	SCROLL_FORWARD = 5,
};
enum
{
	K_W = 13,
	K_S = 1,
	K_LEFT = 124,
	K_UP = 125
	K_RIGHT = 123,
	K_DOWN = 126,
};



# elif __linux__ 
#	include <mlx.h>
#	include <X11/X.h>
#	define WIN_WIDTH 800
#	define WIN_HEIGHT 800
#	define SCALE 4
#	define ZOOM 0.2
#	define COL_TAB_SIZE 16
#	define MAX_ITER	250
enum // events for macos 
{
	ON_KEYDOWN		= KeyPress,
	ON_KEYUP		= KeyRelease,
	ON_MOUSEDOWN	= ButtonPress,
	ON_MOUSEUP		= ButtonRelease,
	ON_MOUSEMOVE	= MotionNotify,
	ON_EXPOSE		= Expose,
	ON_DESTROY		= DestroyNotify,
};

enum // mouse clicks for macos 
{
	M_LEFT_CLICK		= 1,
	M_RIGHT_CLICK		= 2,
	M_MIDDLE_CLICK		= 3,
	M_SCROLL_BACKWARD	= 4,
	M_SCROLL_FORWARD	= 5,
};

enum
{
	K_W		= 119,
	K_S		= 115,
	K_LEFT	= 65361,
	K_UP	= 65362,
	K_RIGHT	= 65363,
	K_DOWN	= 65364,
	K_ESCP	= 65307,
	K_C		= 99,
	K_CTRL	= 65507,
};
# endif

typedef	struct	s_hsl
{
	double hue; // hue from 0 to 3560
	double sat; // sat from 0 to 100
	double light; // light from 0 to 100
}	t_hsl;

typedef union
{
	int	value;
	struct
	{
		unsigned char r; // range from 0 to 255
		unsigned char g;
		unsigned char b;
		unsigned char a;
	};
}	t_color;


typedef	struct s_colors
{
	t_color a;
	t_color b;
	t_color c;
	t_color d;
	t_color e;
}	t_colors;

typedef struct s_complex
{
	double real;
	double im;
}	t_complex;

typedef struct s_view
{
	double	center_x;
	double 	center_y;
	double	real_coords[WIN_WIDTH];
	double	imag_coords[WIN_HEIGHT];
	double	scale;
	double	pixel_to_complex;
}	t_view;


typedef struct s_image
{
	void	*data;
	void	*addr;
	int		bitspp; // how many bits per pixel
	int		bytespp; // how many bytes per pixel, 8 bits in 1 byte, 32/8 = 4
	int		total_bytes;
	int		pixels_per_line;
	int		size_line;
	int		endian;  	//in this project, it is always 0, which means little endian. 
						//example: 0x12345678, the 0x78 is the first byte, 0x12 is the last byte
						//in endianess, the first byte corespond to red
}	t_myimage;

typedef struct s_m_struct t_m_struct;

 //here we define the function pointer called t_iteration_func
//need to place the functiopn definition lower so my compiler understands 
typedef	struct s_fractal
{
	int					fractal_type;
	double				center_x;
	double 				center_y;
	t_complex 			c_constant; // trhis is the input
	//int			iter_limit; //maybe this becomes a GV
	void				(*iteration_f)(t_m_struct *data, t_complex *z, t_complex *c);
	int					iter; // this is the result of the function pointer 
	double				magnitude;
	t_complex			z;
	double				smooth_iter;
}	t_fractal;

struct s_m_struct
{
	void		*mlx_ptr; //a void pointer that contains the base_address returned by mlx_init() 
	void		*win;
	int 		final_color;
	int			request_render;		// when the render is requested, it will be set to 1
	int			is_control_pressed;
	t_myimage	image;
	t_view		view;
	t_fractal	f;
	t_colors	colors;
	
};


void	fractal_set(t_m_struct *data);
void	init_img(t_m_struct *data);
void	select_palette(t_m_struct *data);

void	event_mouse_init(t_m_struct *data);
void	events_keys_init(t_m_struct *data);
int		mouse_down(int mouse_down, int x, int y, t_m_struct *data);
int		key_down(int key_code, t_m_struct *data);
int		mouse_move(int x, int y, t_m_struct *data);

void	put_pixel_to_image(t_m_struct *data, int x, int y);
void	view_init(t_m_struct *data);

void	zoom(t_m_struct *data, int x, int y, double zoom);
void	view_update(t_m_struct *data);
int		request_render(t_m_struct *data);
int		render(t_m_struct *data);
void	view_draw(t_m_struct *data);
void	set_color(t_m_struct *data, t_complex *z);
void	set_gradient(t_m_struct *data);

//int		draw_square(t_complex z);



//int	check_limit_upper(int value, int limit_upper);
//int check_limit_lower(int value, int limit_lower);
float	ft_atof(char *s);
int		ft_is_int(char *s);

void	ft_exit_fractol(t_m_struct *data, char *error);
int		handle_destroy(t_m_struct *data);


#endif
