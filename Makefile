NAME = fdf
CC = cc

PRINTF_DIR = srcs/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRCS = srcs/main.c \
	   srcs/parser/parser.c \
	   srcs/gnl/get_next_line.c \
	   srcs/gnl/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L/minilibx-linux -Imlx_linux -lXext -lX11 -lm $(PRINTF) $(LIBFT) $(MLX) -o $(NAME) -g

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

fclean: clean
	rm -f $(NAME) && $(MAKE) fclean -C $(LIBFT_DIR) && $(MAKE) fclean -C $(PRINTF_DIR)


clean:
	rm -f $(OBJS) && $(MAKE) clean -C $(LIBFT_DIR) && $(MAKE) clean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
