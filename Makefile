NAME = fdf
CC = cc

PRINTF_DIR = srcs/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = MacroLibX
MLX = $(MLX_DIR)/libmlx.so

SRCS = srcs/main.c \
	   srcs/parser/parser.c \
	   srcs/parser/parser_utils.c \
	   srcs/gnl/get_next_line.c \
	   srcs/gnl/get_next_line_utils.c \
	   srcs/pixel/pixel.c \
	   srcs/pixel/bresenham.c \
	   srcs/mlx/mlx.c \
	   srcs/events/events.c \
	   srcs/mem_man/mem_man.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(MLX) $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -lSDL2 -lm $(PRINTF) $(LIBFT) $(MLX) -o $(NAME) -g

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR):
	git clone https://github.com/seekrs/MacroLibX.git 

$(MLX): $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

fclean: clean
	rm -f $(NAME) && $(MAKE) fclean -C $(LIBFT_DIR) && $(MAKE) fclean -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS) && $(MAKE) clean -C $(LIBFT_DIR) && $(MAKE) clean -C $(PRINTF_DIR) && rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
