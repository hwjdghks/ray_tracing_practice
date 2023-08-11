CFLAGS = -Wall -Werror -Wextra
NAME = a.out

MLX_DIR = ../minilibx_mms_20210621/
MLX = libmlx.dylib
LIB_MLX = -lmlx -L$(MLX_DIR)

SRC_DIR = src/

SRC = main.c \
		color.c \
		hook.c \
		image.c \
		initialize.c \
		utils.c

OBJ = $(SRC:.c=.o)
SRC_FILE = $(addprefix $(SRC_DIR), $(SRC))
OBJ_FILE = $(addprefix $(SRC_DIR), $(OBJ))

INC_DIR = inc

.c.o:
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $<

all: $(NAME)

$(NAME) : $(OBJ_FILE)
	make -C $(MLX_DIR)
	install_name_tool -id $(MLX_DIR)$(MLX) $(MLX_DIR)$(MLX)
	$(CC) $(LIB_MLX) $(OBJ_FILE)

clean:
	$(RM) $(OBJ_FILE) $(NAME)

.PHONY: all clean