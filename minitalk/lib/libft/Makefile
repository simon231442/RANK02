### VARIABLE DECLARIATIONS ###

NAME = libft.a

CC = gcc

# Compilations Flags
CFLAGS = -Wall -Wextra -Werror -g

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
	ft_str_expand.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_atoi.c \
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


OBJS = $(SRCS:%.c=%.o)


#########################################################################




### (COMPILATION) RULES ###

.DEFAULT_GOAL=all


# $<: first file on the right side of ':'
# $@: file on the left side of ':'
# 
#
# Implicit rule for compiling .o from .c: is there by default, unless you remove it:
#%.o: %.c
#	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


# Règle pour créer la bibliothèque

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

### PHONY RULES ###


.PHONY: all clean fclean re bonus

all: $(NAME)

# Règles supplémentaires
clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

