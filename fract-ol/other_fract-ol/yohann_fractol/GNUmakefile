CC = gcc

LIBDIR = mlx-linux

CFLAGS = -I$(LIBDIR) -c -Wall -Wextra -Werror
LFLAGS = -L$(LIBDIR) -L/usr/lib -lXext -lX11 -lm -lbsd

NAME = fract-ol
SRC = ft_cplx_ops.c ft_cplx_extra.c fractol_main.c fractol_utils_1.c fractol_utils_2.c fractol_utils_3.c fractol_parsing.c
OBJ = $(SRC:%.c=%.o)
LIBOBJ = \
		$(LIBDIR)/obj/mlx_clear_window.o \
		$(LIBDIR)/obj/mlx_destroy_display.o \
		$(LIBDIR)/obj/mlx_destroy_image.o \
		$(LIBDIR)/obj/mlx_destroy_window.o \
		$(LIBDIR)/obj/mlx_expose_hook.o \
		$(LIBDIR)/obj/mlx_flush_event.o \
		$(LIBDIR)/obj/mlx_get_color_value.o \
		$(LIBDIR)/obj/mlx_get_data_addr.o \
		$(LIBDIR)/obj/mlx_hook.o \
		$(LIBDIR)/obj/mlx_init.o \
		$(LIBDIR)/obj/mlx_int_anti_resize_win.o \
		$(LIBDIR)/obj/mlx_int_do_nothing.o \
		$(LIBDIR)/obj/mlx_int_get_visual.o \
		$(LIBDIR)/obj/mlx_int_param_event.o \
		$(LIBDIR)/obj/mlx_int_set_win_event_mask.o \
		$(LIBDIR)/obj/mlx_int_str_to_wordtab.o \
		$(LIBDIR)/obj/mlx_int_wait_first_expose.o \
		$(LIBDIR)/obj/mlx_key_hook.o \
		$(LIBDIR)/obj/mlx_loop_hook.o \
		$(LIBDIR)/obj/mlx_loop.o \
		$(LIBDIR)/obj/mlx_mouse_hook.o \
		$(LIBDIR)/obj/mlx_mouse.o \
		$(LIBDIR)/obj/mlx_new_image.o \
		$(LIBDIR)/obj/mlx_new_window.o \
		$(LIBDIR)/obj/mlx_pixel_put.o \
		$(LIBDIR)/obj/mlx_put_image_to_window.o \
		$(LIBDIR)/obj/mlx_rgb.o \
		$(LIBDIR)/obj/mlx_screen_size.o \
		$(LIBDIR)/obj/mlx_set_font.o \
		$(LIBDIR)/obj/mlx_string_put.o \
		$(LIBDIR)/obj/mlx_xpm.o \

.PHONY:
	all clean fclean mlx

all: mlx $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBOBJ) $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(SRC)

mlx:
	$(MAKE) -C $(LIBDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all