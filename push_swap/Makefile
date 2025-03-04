.DEFAULT_GOAL=all

NAME = push_swap

CC = cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -g

CPPFLAGS += -I includes
CPPFLAGS += -I srcs/libft

SRCS += srcs/ps_main.c
SRCS += srcs/ps_args_prepare.c
SRCS += srcs/ps_args_check_no_arg.c
SRCS += srcs/ps_args_check_non_numeric.c
SRCS += srcs/ps_args_check_over_and_underflow.c
SRCS += srcs/ps_args_check_duplicate.c
SRCS += srcs/ps_args_count.c
SRCS += srcs/ps_args_to_int_tab.c
SRCS += srcs/ps_args_int_sort.c
SRCS += srcs/ps_args_free.c
SRCS += srcs/ps_stack_a_create.c
SRCS += srcs/ps_error.c

OBJS = $(SRCS:%.c=%.o)

LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS):%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

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
