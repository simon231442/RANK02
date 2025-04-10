/* ************************************************************************** */
/*                                                           *                */
/*                                                          * *               */
/*   fractol_main.c                                        *   *              */
/*                                                        * * * *             */
/*   By: srenaud <srenaud@student.42lausanne.ch>         *       *            */
/*                                                      * *     * *           */
/*   Created: 2025/02/13 14:25:39 by srenaud           *   *   *   *          */
/*   Updated: 2025/02/13 14:25:39 by srenaud          * * * * * * * *         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_env env;

	env_init(&env);
	fractol_parse(&env, ac, av);
	env.mlx.mlx = mlx_init();
	env.mlx.win = mlx_new_window(env.mlx.mlx, WIN_X, WIN_Y, "fract-ol");
	env.img.img = mlx_new_image(env.mlx.mlx, WIN_X, WIN_Y); //renvoie un ptr sur image
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel,
		&env.img.line_length, &env.img.endian); 
		//renvoie un point sur char *(ptr sur premier pixel), par = ptr sur image, nb bit/pixel, taille d'une ligne, emdian info)
	ft_printf("Bits per pixel: %d\n", env.img.bits_per_pixel);
	ft_printf("Line length: %d\n", env.img.line_length);
	ft_printf("Endianness: %d (0 = little endian, 1 = big endian)\n", env.img.endian);
	fractol_anti_aliasing_neighbors_init(&env.img ,&env.neighbors);
	fractal_render(&env);
	//test_render(&env); // test
	mlx_key_hook(env.mlx.win, event, &env);
	mlx_mouse_hook(env.mlx.win, fractol_zoom, &env);
	mlx_hook(env.mlx.win, DestroyNotify, 0, close_window, &env);
	mlx_loop(env.mlx.mlx);
	return (0);
}
