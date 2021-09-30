INCS		= includes
LIB			= libft
LIB.A		= libft.a
SRC			= read_map_util_2.c read_map_util.c read_map.c so_long.c so_long_util_2.c so_long_util.c
OBJ			= $(SRC:.c=.o)
NAME		= so_long
FLAGS		= -Wall -Wextra -Werror -I${INCS} 
OS 			= $(shell uname)
ifeq (${DEBUG}, 1)
	FLAGS	+= -g
endif

ifeq ($(OS), Linux)
	FLAGS_PLUS	= -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
	SRC 	+= destroy_linux.c
else
	FLAGS_PLUS	= -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g3 -O0 
	SRC 	+= destroy_mac.c
endif
		
all: $(NAME) 

$(LIB.A):
		make -C $(LIB)
		@mv $(LIB)/$(LIB.A) .

$(NAME): $(LIB.A) $(OBJ)
		gcc -o $@ $(OBJ) $(LIB.A) $(FLAGS) $(FLAGS_PLUS)


%.o: %.c
		cc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJ) $(LIB.A)
		make clean -C $(LIB)

fclean:		clean
		$(RM)  $(NAME) $(LIB.A)
		make fclean -C $(LIB)

re:		fclean all

.PHONY: 	all clean fclean re
