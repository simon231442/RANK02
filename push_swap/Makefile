NAME = push_swap

CC = cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

CPPFLAGS += -I includes
CPPFLAGS += -I srcs/libft

SRCS += srcs/ps_main.c
SRCS += srcs/ps_arg_check_no_arg.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	make -C $(LIBFT_DIR)

.PHONY: all
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

.PHONY: clean
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

.PHONY: fclean
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

.PHONY: re
re: fclean all