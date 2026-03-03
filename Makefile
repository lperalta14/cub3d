CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR) -I$(HEADERSDIR) -g
LDFLAGS = -L$(LIBFTDIR) -lft 


NAME = minishell

LIBFTDIR = libft
LIBFTNAME = $(LIBFTDIR)/libft.a

OBJDIR = obj

HEADER_FILES  = \
		 \

HEADERS = $(addprefix $(HEADERSDIR)/, $(HEADER_FILES))

HEADERSDIR = include

BASEDIR= src
MAINSRC = \
		main.c \

PARSINDIR = $(BASEDIR)/parsing
PARSINGSRC = \
		\

TEXTUREDIR = $(PARSINGDIR)/texture
TEXTUREDIRSRC = \
		\

	$(addprefix $(BASEDIR)/, $(MAINSRC)) \
	$(addprefix $(PARSINDIR)/, $(PARSINGSRC)) \
	$(addprefix $(TEXTUREDIR)/, $(TEXTUREDIRSRC)) \

OBJ = $(patsubst $(BASEDIR)/%, $(OBJDIR)/%, $(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFTNAME) $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "Cub3d compiled successfully!"

$(OBJDIR)/%.o: $(BASEDIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "Compiling Cub3d $$(find $(OBJDIR) -type f | wc -l)/$(words $(OBJ)) files\r"

$(LIBFTNAME):
	@make bonus -s -C $(LIBFTDIR)

clean:
	@make clean -s -C $(LIBFTDIR)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -s -C $(LIBFTDIR)
	@rm -f $(NAME)

re: fclean all