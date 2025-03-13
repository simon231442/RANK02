################################################################################
#                               DIRECTORIES                                    #
################################################################################
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include
LIB_DIR = lib

################################################################################
#                                 LIBRARY                                      #
################################################################################
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

################################################################################
#                                 SERVER                                       #
################################################################################
NAME_SERV = $(BIN_DIR)/server

FILE_SERV = $(SRC_DIR)/server/server.c \

SRC_SERV = $(FILE_SERV)
OBJ_S = $(SRC_SERV:$(SRC_DIR)/%.c=$(OBJ_SERV)/%.o)

################################################################################
#                                 CLIENT                                       #
################################################################################
NAME_CLIENT = $(BIN_DIR)/client

FILE_CLIENT = $(SRC_DIR)/client/client.c \

SRC_CLIENT = $(FILE_CLIENT)
OBJ_C = $(SRC_CLIENT:$(SRC_CLIENT)/%.c=$(OBJ_CLIENT)/%.o)

################################################################################
#                             COMPILER OPTIONS                                 #
################################################################################
CC = cc
CPPFLAG = -I$(INC_DIR)
CFLAG = -Wall -Wextra -Werror -g
LIB = -L$(LIBFT_DIR) -lft

################################################################################
#                              TARGETS & RULES                                 #
################################################################################

all: init $(LIBFT) $(NAME_SERV) $(NAME_CLIENT)

init: 
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)/server
	@mkdir -p $(OBJ_DIR)/client
	@echo "project structure initialized"

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "libft ready"

$(NAME_SERV): $(LIBFT) $(OBJ_SERV)
	@$(CC) $(OBJ_S) $(LIB) -o $(NAME_SERV)
	@echo "server binary created : run with ./bin/server"

$(NAME_CLIENT): $(LIBFT) $(OBJ_CLIENT)
	@$(CC) $(OBJ_C) $(LIB) -o $(NAME_CLIENT)
	@echo "client binary created : run with ./bin/client"

################################################################################
#                               OBJS & RULES                                   #
################################################################################

$(OBJ_SERV)/%.o: $(FILE_SERV)/%.c
	@$(CC) $(CPPFLAG) $(CFLAG) -c $< -o $@

	$(OBJ_CLIENT)/%.o: $(FILE_CLIENT)/%.c
	@$(CC) $(CPPFLAG) $(CFLAG) -c $< -o $@




