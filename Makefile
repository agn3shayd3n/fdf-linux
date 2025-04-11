NAME = fdf

SRCS = main.c read_map.c projection.c line_union.c fdf_utils.c ft_split.c draw.c \
get_next_line.c get_next_line_utils.c color.c key_hook.c text_panel.c handle_close.c \
build_win.c \

OBJ_DIR = obj

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx -I.
MLX_FLAGS = -Lminilibx -lmlx -lXext -lX11 -lm -lbsd
RM = rm -f

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)FDF COMPILED ✧*｡٩(ˊᗜˋ*)و✧*｡$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)CLEANED OBJECT FILES ╰( ´・ω・)つ──☆ *:・ﾟ✧$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)CLEANED EXECUTABLE °•°٩(◕‿◕｡)°•°$(RESET)"

re: fclean all

.PHONY: all clean fclean re