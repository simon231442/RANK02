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
SRCS += srcs/ps_args_struct_init.c
SRCS += srcs/ps_args_prepare.c
SRCS += srcs/ps_args_check_non_numeric.c
SRCS += srcs/ps_args_check_over_and_underflow.c
SRCS += srcs/ps_args_check_duplicate.c
SRCS += srcs/ps_args_count.c
SRCS += srcs/ps_args_to_int_tab.c
SRCS += srcs/ps_args_int_sort.c
SRCS += srcs/ps_args_check_already_sorted.c
SRCS += srcs/ps_args_free.c
SRCS += srcs/ps_stack_a_create.c
SRCS += srcs/ps_error.c
SRCS += srcs/ps_stack_move_utils_swap.c
SRCS += srcs/ps_stack_move_sa.c
SRCS += srcs/ps_stack_move_sb.c
SRCS += srcs/ps_stack_move_ss.c
SRCS += srcs/ps_stack_move_utils_push.c
SRCS += srcs/ps_stack_move_pa.c
SRCS += srcs/ps_stack_move_pb.c
SRCS += srcs/ps_stack_move_utils_rotate.c
SRCS += srcs/ps_stack_move_ra.c
SRCS += srcs/ps_stack_move_rb.c
SRCS += srcs/ps_stack_move_rr.c
SRCS += srcs/ps_stack_move_utils_reverse_rotate.c
SRCS += srcs/ps_stack_move_rra.c
SRCS += srcs/ps_stack_move_rrr.c
SRCS += srcs/ps_stack_move_rrb.c
SRCS += srcs/ps_stack_sort.c
SRCS += srcs/ps_stack_sort_3.c
SRCS += srcs/ps_stack_sort_4.c
SRCS += srcs/ps_stack_sort_5.c
SRCS += srcs/ps_stack_sort_radix.c

SRCS += srcs/ps_stack_utils_display.c
SRCS += srcs/ps_stack_utils_display_line.c
SRCS += srcs/ps_args_int_utils_display.c

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
