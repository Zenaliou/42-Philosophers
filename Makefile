#COMPILATION
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -g3

#DIRECTORIES
SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE_DIR = includes/

#SOURCES
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

#NAME
NAME = philo

#COLORS
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

#RULES
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ Compilation de $(NAME) réussie!$(NC)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/philosophers.h
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compilation de $< réussie.$(NC)"

clean:
	rm -rf $(OBJ_DIR)
	@echo "$(RED)Fichiers objets supprimés.$(NC)"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)Exécutable $(NAME) supprimé.$(NC)"

re: fclean all