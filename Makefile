# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PINK = \033[0;35m
NC=\033[0m  # (reset)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR) -I$(HEADERSDIR) $(MLX42_INC) -g
LDFLAGS = -L$(LIBFTDIR) -lft
MLX42_FLAGS = -ldl -lglfw -pthread -lm

NAME = cubed

LIBFTDIR = my_lib
LIBFTNAME = $(LIBFTDIR)/libft.a

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = -I$(MLX42_DIR)/include

OBJDIR = obj
HEADERSDIR = include

BASEDIR = src

MAINSRC = \
	main.c \
	check_file.c \
	init_data.c

PARSINDIR = $(BASEDIR)/parsing
PARSINGSRC = \

UTILS = \
	utils/valid_char_in_map.c

TEXTUREDIR = $(PARSINDIR)/texture
TEXTUREDIRSRC = \

SRC = \
	$(addprefix $(BASEDIR)/, $(MAINSRC)) \
	$(addprefix $(BASEDIR)/, $(UTILS)) \
	$(addprefix $(PARSINDIR)/, $(PARSINGSRC)) \
	$(addprefix $(TEXTUREDIR)/, $(TEXTUREDIRSRC))

OBJ = $(patsubst $(BASEDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(MLX42_LIB) $(NAME)

$(MLX42_LIB):
	@echo "Compiling MLX42..."
	@mkdir -p $(MLX42_DIR)/build
	@cd $(MLX42_DIR)/build && cmake .. && make

$(NAME): $(LIBFTNAME) $(OBJ)
	@$(CC) $(OBJ) $(MLX42_LIB) $(LDFLAGS) $(MLX42_FLAGS) -o $(NAME)
	@echo "$(GREEN)CCCompiling Cub3d $$(find $(OBJDIR) -type f | wc -l)/$(words $(OBJ)) files\r$(NC)"
	@echo "$(GREEN)  Cub3D compiled successfully!$(NC)"

$(OBJDIR)/%.o: $(BASEDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTNAME):
	@make --no-print-directory -C $(LIBFTDIR)

clean:
	@make --no-print-directory clean -C $(LIBFTDIR)
	@rm -rf $(OBJDIR)

fclean: clean
	@make --no-print-directory fclean -C $(LIBFTDIR)
	@rm -f $(NAME)

re: fclean all