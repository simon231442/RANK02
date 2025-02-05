/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:15:04 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/20 11:15:04 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */
/*
** Initialize mlx.
**
** @return	void*	the mlx instance
*/
void	*mlx_init();
/*
** Create a new window.
**
** @param	void *mlx_ptr	the mlx instance pointer;
** @param	int  size_x		the width of the window;
** @param	int  size_y		the height of the window;
** @param	char *title		the title of the window;
** @return	void*			the window instance pointer.
*/
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

/*
** Gets the data address of the current image.
**
** @param	void *img_ptr			the image instance;
** @param	int  *bits_per_pixel	a pointer to where the bpp is written;
** @param	int  *size_line		a pointer to where the line is written;
** @param	int  *endian		a pointer to where the endian is written;
** @return	char*				the memory address of the image.
*/
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);

# include <mlx.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_data 
{
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_data;

typedef struct s_vars
{
    void	*mlx;
    void	*win;
    t_data	img;
    double	angle;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	render_next_frame(t_vars *vars)
{
    int		x;
    int		y;
    double	c_re = -0.7;
    double	c_im = 0.27015;
    double	new_re, new_im, old_re, old_im;
    int		max_iterations = 300;
    int		color;

    // Clear the image
    for (y = 0; y < 1080; y++)
    {
        for (x = 0; x < 1920; x++)
        {
            my_mlx_pixel_put(&vars->img, x, y, 0x00000000); // Black color
        }
    }

    // Draw Julia set
    for (y = 0; y < 1080; y++)
    {
        for (x = 0; x < 1920; x++)
        {
            new_re = 1.5 * (x - 1920 / 2) / (0.5 * 1920);
            new_im = (y - 1080 / 2) / (0.5 * 1080);
            int i;
            for (i = 0; i < max_iterations; i++)
            {
                old_re = new_re;
                old_im = new_im;
                new_re = old_re * old_re - old_im * old_im + c_re;
                new_im = 2 * old_re * old_im + c_im;
                if ((new_re * new_re + new_im * new_im) > 4) break;
            }
            color = (i * 255 / max_iterations) << 16 | (i * 255 / max_iterations) << 8 | (i * 255 / max_iterations);
            my_mlx_pixel_put(&vars->img, x, y, color);
        }
    }

    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
    return (0);
}

int	main(void)
{
    t_vars	vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Julia Set");
    vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
    vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
                                &vars.img.endian);

    mlx_loop_hook(vars.mlx, render_next_frame, &vars);
    mlx_loop(vars.mlx);

    return (0);
}