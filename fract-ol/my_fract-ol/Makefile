.DEFAULT_GOAL=all

NAME        = fractol

CC = cc
CFLAGS      += -Wall
CFLAGS      += -Wextra
CFLAGS      += -Werror

CPPFLAGS    += -I srcs/libft
CPPFLAGS    += -I srcs/libmlx
CPPFLAGS    += -I includes

SRCS        += srcs/fractol_main.c
SRCS		+= srcs/env_init.c
SRCS		+= srcs/fractol_parse.c
SRCS		+= srcs/event.c
SRCS		+= srcs/fractol_quit.c
SRCS		+= srcs/fractal_render.c
SRCS		+= srcs/mandlebrot.c
SRCS		+= srcs/julia.c
SRCS		+= srcs/fractol_color_gradient.c
SRCS		+= srcs/fractol_anti_aliasing_neighbors_init.c
SRCS		+= srcs/fractol_anti_aliasing.c
SRCS		+= srcs/fractol_mandelbrot_iter_smooth.c
SRCS		+= srcs/sierpinski.c
SRCS		+= srcs/my_mlx_pixel_put.c
SRCS		+= srcs/fractol_zoom.c

#test
SRCS		+= srcs/test_render.c

OBJS        = $(SRCS:.c=.o)

srcs/libft/libft.a:
	$(MAKE) -C srcs/libft all

srcs/libmlx/libmlx.a:
	$(MAKE) -C srcs/libmlx

$(NAME): $(OBJS) srcs/libft/libft.a srcs/libmlx/libmlx.a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) -L srcs/libft -lft -L srcs/libmlx -lmlx -lXext -lX11 -lm

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	$(MAKE) -C srcs/libft clean
	$(MAKE) -C srcs/libmlx clean
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
