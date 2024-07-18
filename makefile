CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC_DIR = src
FT_PRINTF_DIR = ft_printf

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
