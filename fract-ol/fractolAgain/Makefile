.DEFAULT_GOAL=all

NAME        = fractol

CC = cc
CFLAGS      += -Wall
CFLAGS      += -Wextra
CFLAGS      += -Werror

CPPFLAGS    += -I srcs/libft
CPPFLAGS    += -I srcs/libmlx
CPPFLAGS    += -I includes

# Fichiers principaux
SRCS        += srcs/fractol_main.c
SRCS        += srcs/fractol_env_init.c
SRCS        += srcs/fractol_parsing.c

# Fichiers MLX
SRCS        += srcs/fractol_mlx_start.c
SRCS        += srcs/fractol_mlx_exit.c

# Fichiers de rendu
SRCS        += srcs/fractol_render.c
SRCS        += srcs/fractol_render_loop.c
SRCS        += srcs/fractol_pixel_draw.c
SRCS        += srcs/fractol_pixel_put.c
SRCS        += srcs/fractol_pixel_color.c

# Fichiers mathématiques
SRCS        += srcs/fractol_math_mandlebrot.c
SRCS        += srcs/fractol_math_julia.c

# Fichiers de coloration
SRCS        += srcs/fractol_math_color_gradient.c
SRCS        += srcs/fractol_math_color_rainbow.c
SRCS        += srcs/fractol_math_color_fire.c
SRCS        += srcs/fractol_math_color_bands.c
SRCS        += srcs/fractol_math_color_psychedelic_1.c
SRCS        += srcs/fractol_math_color_psychedelic_2.c
SRCS        += srcs/fractol_math_color_ocean.c

# Fichiers d'événements
SRCS        += srcs/fractol_event.c
SRCS        += srcs/fractol_event_keyhook.c
SRCS        += srcs/fractol_event_zoom.c

OBJS        = $(SRCS:.c=.o)

srcs/libft/libft.a:
	$(MAKE) -C srcs/libft

srcs/libmlx/libmlx.a:
	$(MAKE) -C srcs/libmlx

$(NAME): $(OBJS) srcs/libft/libft.a srcs/libmlx/libmlx.a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) -L srcs/libft -lft \
		-L srcs/libmlx -lmlx -lXext -lX11 -lpthread -lm -lz

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
