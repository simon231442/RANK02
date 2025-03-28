# Noms Executables
CLIENT = client
SERVER = server

# Noms Repertoires
SRC_DIR = src
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
OBJ_DIR = obj

# Fichiers sources
SRC_CLIENT = $(SRC_DIR)/client.c
SRC_SERVER = $(SRC_DIR)/server.c

# Fichiers objets
OBJ_CLIENT = $(OBJ_DIR)/client.o
OBJ_SERVER = $(OBJ_DIR)/server.o

# Librairies
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/ft_printf.a

# Options de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Regle pour "make"
all: $(CLIENT) $(SERVER)

# Compilation des executables
$(CLIENT): $(OBJ_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(PRINTF) $(LIBFT)

$(SERVER): $(OBJ_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER) $(PRINTF) $(LIBFT)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Creation du dossier obj si non existant
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilation des librairies
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Efface tous les objets
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

# Efface tout
fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

# Efface et recompile
re: fclean all

# Eviter les conflits de noms avec des fichiers existants
.PHONY: all clean fclean re
