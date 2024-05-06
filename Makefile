CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

#SRC = $(filter-out so_long.c, $(wildcard *.c))
SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = so_long

LINK = -lmlx -framework OpenGL -framework AppKit

libft = libft.a

all: $(NAME) 

$(libft):
	make -C libft
	cd libft && mv libft.a ../

$(NAME) : $(OBJ) $(libft)
	$(CC) $(CFLAGS) $(OBJ) $(LINK) $(libft) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME) libft.a
	make -C libft fclean

re : fclean all

.PHONY : all clean fclean

.SECONDARY : $(OBJ)