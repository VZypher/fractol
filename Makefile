NAME = fractol
CFLAGS = -Wall -Wextra -Werror -g3 -Ilibft -I./minilibx-linux-master -O3
libft = ./libft
minilibx = ./minilibx-linux-master
mlx = $(minilibx)/libmlx_Linux.a
CC = cc
SRC = fractol.c \
	fractol_utils.c \
	colors.c \
	math.c \
	hook.c 

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS = $(OBJ:.o=.d)

all: $(OBJ_DIR) libft $(NAME) 

$(OBJ_DIR)/%.o: %.c fractol.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -MMD -MP -I$(libft) -I$(minilibx)

$(NAME): $(OBJ) libft $(mlx)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(libft) -lft $(mlx) -L$(minilibx) -lXext -lX11 -lm -lz

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft:
	make -C $(libft)

$(mlx):
	make -C $(minilibx)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re