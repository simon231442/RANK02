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

SRC_SERV = $(SRC_DIR)/server/server.c \

OBJ_DIR_SERV = $(OBJ_DIR)/server
PATTERN_OBJ_SERV = $(SRC_SERV:$(SRC_DIR)/server%.c=$(OBJ_DIR_SERV)/%.o)

################################################################################
#                                 CLIENT                                       #
################################################################################
NAME_CLIENT = $(BIN_DIR)/client

SRC_CLIENT = $(SRC_DIR)/client/client.c \

OBJ_DIR_CLIENT = $(OBJ_DIR)/client
PATTERN_OBJ_CLIENT = $(SRC_CLIENT:$(SRC_DIR)/client%.c=$(OBJ_DIR_CLIENT)/%.o)

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

$(NAME_SERV): $(LIBFT) $(PATTERN_OBJ_SERV)
	@$(CC) $(PATTERN_OBJ_SERV) $(LIB) -o $(NAME_SERV)
	@echo "server binary created : run with ./bin/server"

$(NAME_CLIENT): $(LIBFT) $(PATTERN_OBJ_CLIENT)
	@$(CC) $(PATTERN_OBJ_CLIENT) $(LIB) -o $(NAME_CLIENT)
	@echo "client binary created : run with ./bin/client"

################################################################################
#                               OBJS & RULES                                   #
################################################################################

$(OBJ_DIR_SERV)/%.o: $(SRC_DIR)/server/%.c
	@$(CC) $(CPPFLAG) $(CFLAG) -c $< -o $@

$(OBJ_DIR_CLIENT)/%.o: $(SRC_DIR)/client/%.c
	@$(CC) $(CPPFLAG) $(CFLAG) -c $< -o $@




