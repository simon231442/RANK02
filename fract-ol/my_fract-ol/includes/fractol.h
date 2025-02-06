/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:43:51 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/21 18:43:51 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// libraries
# include "libft.h"
# include "mlx.h"

typedef struct s_vars
{
    void    *mlx;
    void    *win;
}   t_vars;

typedef struct s_data
{
    void    *img;
    char    *addr;
    int		bits_per_pixel;
    int		line_length;
    int     endian;
}   t_data;

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


#endif