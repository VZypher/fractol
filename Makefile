NAME = fractol
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3
libft = ./libft
minilibx = ./minilibx-linux-master
mlx = $(minilibx)/libmlx_Linux.a
CC = cc
SRC = fractol.c \
	fractol_utils.c \
	hook.c \
	julia.c \
	math.c	\
	colors.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS = $(OBJ:.o=.d)

all: $(OBJ_DIR) libft $(NAME) 

$(OBJ_DIR)/%.o: %.c libft/libft.a minilibx-linux-master/libmlx_Linux.a
	$(CC) $(CFLAGS) -o $@ -c $< -I$(libft) -I$(minilibx)

-include $(DEPS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(libft) $(mlx) -L$(minilibx) -lXext -lX11 -lm -lz -lft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(mlx):
	make -C $(minilibx)

libft:
	make -C $(libft)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(libft) clean
	make -C $(minilibx) clean

fclean: clean
	rm -f $(NAME)
	make -C $(libft) fclean

re: fclean all

.PHONY: all clean fclean re libft