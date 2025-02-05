/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:20:43 by ylabussi          #+#    #+#             */
/*   Updated: 2024/11/25 14:53:43 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

static int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_settings		parse_input(int argc, char const **argv);
static void		default_settings(t_settings *settings);
static void		invalid_param(char const *str);

t_settings	parse_input(int argc, char const **argv)
{
	t_settings	ret;
	int			i;

	if (argc < 2)
		invalid_param("");
	default_settings(&ret);
	i = 0;
	while (++i < argc)
		if (ft_strncmp(argv[i], "--col0=", 7) == 0)
			ret.color_in = hextoi(argv[i] + 7);
	else if (ft_strncmp(argv[i], "--col1=", 7) == 0)
		ret.color_out_1 = hextoi(argv[i] + 7);
	else if (ft_strncmp(argv[i], "--col2=", 7) == 0)
		ret.color_out_2 = hextoi(argv[i] + 7);
	else if (ft_strncmp(argv[i], "--seed=", 7) == 0)
		ret.seed = ftc_atoc((char *) argv[i] + 7);
	else if (ft_strncmp(argv[i], "--mandelbrot", 12) == 0)
		ret.type = 0;
	else if (ft_strncmp(argv[i], "--julia", 7) == 0)
		ret.type = 1;
	else if (ft_strncmp(argv[i], "--mandelbar", 11) == 0)
		ret.type = 2;
	else
		invalid_param(argv[i]);
	return (ret);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

static void	default_settings(t_settings *settings)
{
	settings->color_in = COLOR_IN;
	settings->color_out_1 = COLOR_OUT_1;
	settings->color_out_2 = COLOR_OUT_2;
	settings->type = TYPE;
	settings->seed = cplx_init(0.0, 0.0);
}

static void	invalid_param(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, "the parameter '", 15);
	write(1, str, i);
	write(1, "' is not valid\nvalid parameters are :\n", 38);
	write(1, "\t--col0=<hex color>\n", 20);
	write(1, "\t--col1=<hex color>\n", 20);
	write(1, "\t--col2=<hex color>\n", 20);
	write(1, "\t--seed=<a>+<b>i where a and b are reals\n", 41);
	write(1, "\t--mandelbrot\n", 14);
	write(1, "\t--julia\n", 9);
	write(1, "\t--mandelbar\n", 14);
	exit(1);
}
