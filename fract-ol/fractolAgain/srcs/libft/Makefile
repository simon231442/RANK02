### VARIABLE DECLARIATIONS ###

NAME = libft.a

CC = gcc

# Compilations Flags
CFLAGS = -Wall -Wextra -Werror

# Flags for pre processor things like #include, #define and so on...
CPPFLAGS = -I.

vpath %.c printf/
vpath %.c bonus/

SRCS_PRINTF =	    \
	ft_printf.c  \
	pf_letters.c \
	pf_numbers.c	

SRCS_BONUS =\
	ft_lstnew_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstsize_bonus.c

SRCS =\
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_atoi.c \
	ft_atof.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	$(SRCS_PRINTF)\
	$(SRCS_BONUS)


#########################################################################




### COMPILATION RULES ###

.DEFAULT_GOAL=all

# Silent .o compilation rule
OBJS = $(SRCS:.c=.o)
%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Library creation rule
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "libft : $(NAME) created"

### PHONY RULES ###

.PHONY: all clean fclean re bonus

all: $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "libft : objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "libft : $(NAME) removed"

re: fclean all