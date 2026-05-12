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
NAME_BONUS = cubed_bonus

LIBFTDIR  = my_lib
LIBFTNAME = $(LIBFTDIR)/libft.a

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = -I$(MLX42_DIR)/include

OBJDIR     = obj
OBJDIR_BON = obj_bonus
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

SRC_COMMON = \
	$(addprefix $(BASEDIR)/, $(MAINSRC)) \
	$(addprefix $(PARSINDIR)/, $(PARSINGSRC))\
	$(addprefix $(UTILSDIR)/, $(UTILSSRC)) \
	$(addprefix $(INITDIR)/, $(INITSRC)) \
	$(addprefix $(RENDERDIR)/, $(RENDERSRC)) \
	$(addprefix $(INPUTDIR)/, $(INPUTSRC))

SRC = $(SRC_COMMON) 

RENDERSRC_BON = \
	render_frame_bonus.c \
	cast_ray.c \
	draw_column.c \
	draw_floor_ceiling.c
 
INPUTSRC_BON = \
	handle_input_bonus.c
 
BONUSSRC = \
	minimap_bonus.c \
	mouse_bonus.c
 
SRC_BON = \
	$(BASEDIR)/main_bonus.c \
	$(addprefix $(BASEDIR)/parsing/, $(PARSINGSRC)) \
	$(addprefix $(BASEDIR)/utils/, $(UTILSSRC)) \
	$(addprefix $(BASEDIR)/init/, $(INITSRC)) \
	$(addprefix $(BASEDIR)/render/, $(RENDERSRC_BON)) \
	$(addprefix $(BASEDIR)/input/, $(INPUTSRC_BON)) \
	$(addprefix $(BASEDIR)/bonus/, $(BONUSSRC))

OBJ = $(patsubst $(BASEDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
OBJ_BON = $(patsubst $(BASEDIR)/%.c, $(OBJDIR_BON)/%.o, $(SRC_BON))

.PHONY: all bonus clean fclean re

all: $(MLX42_LIB) $(NAME)

bonus: HEADERSDIR = include
bonus: CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR) -I$(HEADERSDIR) $(MLX42_INC) -g
bonus: $(MLX42_LIB) $(NAME_BONUS)

$(MLX42_LIB):
	@echo "$(YELLOW)Compiling MLX42...$(NC)"
	@mkdir -p $(MLX42_DIR)/build
	@cd $(MLX42_DIR)/build && cmake .. -DCMAKE_BUILD_TYPE=Release > /dev/null && make -s

$(NAME): $(LIBFTNAME) $(OBJ)
	@$(CC) $(OBJ) $(MLX42_LIB) $(LDFLAGS) $(MLX42_FLAGS) -o $(NAME)
	@echo "$(GREEN)  cub3D compiled successfully! ($(words $(OBJ)) files)$(NC)"

$(NAME_BONUS): $(LIBFTNAME) $(OBJ_BON)
	@$(CC) $(OBJ_BON) $(MLX42_LIB) $(LDFLAGS) $(MLX42_FLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)  cub3D_bonus compiled! ($(words $(OBJ_BON)) files)$(NC)"

$(OBJDIR)/%.o: $(BASEDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)  CC $<$(NC)"

$(OBJDIR_BON)/%.o: $(BASEDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)  CC $<$(NC)"

$(LIBFTNAME):
	@make --no-print-directory -C $(LIBFTDIR)

clean:
	@make --no-print-directory clean -C $(LIBFTDIR)
	@rm -rf $(OBJDIR) $(OBJDIR_BON)
	@echo "$(RED)  Objects removed$(NC)"

fclean: clean
	@make --no-print-directory fclean -C $(LIBFTDIR)
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)  $(NAME) and $(NAME_BONUS) removed$(NC)"

re: fclean all