NAME = fractol
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3 -Ilibft -I./minilibx-linux-master -O3
libft = ./libft
minilibx = ./minilibx-linux-master
mlx = $(minilibx)/libmlx_Linux.a
CC = cc
SRC = fractol.c \
	fractol_utils.c 

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS = $(OBJ:.o=.d)

all: $(OBJ_DIR) libft minilibx $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(libft) -I$(minilibx)

-include $(DEPS)

$(NAME): $(OBJ) libft minilibx
	$(CC) $(CFLAGS) -L$(minilibx) -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME) $(OBJ) -L$(libft) -lft $(mlx)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft:
	make -C $(libft)

minilibx:
	make -C $(minilibx)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(libft) clean
	make -C $(minilibx) clean

fclean: clean
	rm -f $(NAME)
	make -C $(libft) fclean

re: fclean all

.PHONY: all clean fclean re libft minilibx