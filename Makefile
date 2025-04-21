NAME = fdf

SRCS = srcs/main.c srcs/read_map.c srcs/projection.c srcs/line_union.c srcs/fdf_utils.c \
srcs/ft_split.c srcs/draw.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/color.c \
srcs/key_hook.c srcs/text_panel.c srcs/handle_close.c srcs/build_win.c \

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