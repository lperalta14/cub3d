RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PINK = \033[0;35m
NC=\033[0m 

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I$(LIBFTDIR) -I$(HEADERSDIR) $(MLX42_INC) -g
LDFLAGS = -L$(LIBFTDIR) -lft
MLX42_FLAGS = -ldl -lglfw -pthread -lm

NAME = cubed

LIBFTDIR  = my_lib
LIBFTNAME = $(LIBFTDIR)/libft.a

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = -I$(MLX42_DIR)/include

OBJDIR     = obj
HEADERSDIR = include
BASEDIR    = src

MAINSRC = \
	main.c

PARSINDIR  = $(BASEDIR)/parsing
PARSINGSRC = \
	check_file.c \
	read_map.c \
	init_data.c \
	texture.c \
	colors.c \
	parse_map.c\
	extract_information.c\

UTILSDIR = $(BASEDIR)/utils
UTILSSRC = \
	valid_char_in_map.c \
	clean_and_exit.c \
	ft_str_digit.c \
	clone_map.c \
	remove_isspaces.c\
	ft_freematrix_i.c\

INITDIR = $(BASEDIR)/init
INITSRC = \
	init_game.c \
	init_player.c \

RENDERDIR = $(BASEDIR)/render
RENDERSRC = \
	render_frame.c \
	cast_ray.c \
	draw_column.c \
	draw_floor_ceiling.c \


INPUTDIR = $(BASEDIR)/input
INPUTSRC = \
	handle_input.c

# Fuentes comunes (sin parsing)
SRC_COMMON = \
	$(addprefix $(BASEDIR)/, $(MAINSRC)) \
	$(addprefix $(UTILSDIR)/, $(UTILSSRC)) \
	$(addprefix $(INITDIR)/, $(INITSRC)) \
	$(addprefix $(RENDERDIR)/, $(RENDERSRC)) \
	$(addprefix $(INPUTDIR)/, $(INPUTSRC))

# Modo normal: incluye parsing real
SRC_REAL = $(SRC_COMMON) \
	$(addprefix $(PARSINDIR)/, $(PARSINGSRC))

# Modo mock: sustituye parsing por init_mock
SRC_MOCK = $(SRC_COMMON) \
	$(BASEDIR)/mock/init_mock.c

ifdef MOCK
SRC = $(SRC_MOCK)
else
SRC = $(SRC_REAL)
endif

OBJ = $(patsubst $(BASEDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all mock clean fclean re

all: $(MLX42_LIB) $(NAME)

mock:
	@$(MAKE) MOCK=1

$(MLX42_LIB):
	@echo "$(YELLOW)Compiling MLX42...$(NC)"
	@mkdir -p $(MLX42_DIR)/build
	@cd $(MLX42_DIR)/build && cmake .. -DCMAKE_BUILD_TYPE=Release > /dev/null && make -s

$(NAME): $(LIBFTNAME) $(OBJ)
	@$(CC) $(OBJ) $(MLX42_LIB) $(LDFLAGS) $(MLX42_FLAGS) -o $(NAME)
	@echo "$(GREEN)  cub3D compiled successfully! ($(words $(OBJ)) files)$(NC)"

$(OBJDIR)/%.o: $(BASEDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)  CC $<$(NC)"

$(LIBFTNAME):
	@make --no-print-directory -C $(LIBFTDIR)

clean:
	@make --no-print-directory clean -C $(LIBFTDIR)
	@rm -rf $(OBJDIR)
	@echo "$(RED)  Objects removed$(NC)"

fclean: clean
	@make --no-print-directory fclean -C $(LIBFTDIR)
	@rm -f $(NAME)
	@echo "$(RED)  $(NAME) removed$(NC)"

re: fclean all