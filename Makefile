INCS		= includes
LIB		= libft
LIB.A		= libft.a
SRC		= share/creat_listd.c share/operation_1.c share/operation_2.c share/replace_by_ranking.c share/parse_list.c
OBJ		= $(SRC:.c=.o)
NAME		= so_long
FLAGS		= -Wall -Wextra -Werror -I${INCS} -I.
ifeq (${DEBUG}, 1)
	FLAGS	+= -g
endif

OS = $(shell uname)

ifeq($(OS), Linux)
	FLAGS   += -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
else
	FLAGS	+=
		
all: $(NAME) 

$(LIB.A):
		make -C $(LIB)
		@mv $(LIB)/$(LIB.A) .

$(NAME): $(LIB.A) $(OBJ)
		gcc -o $@ $(OBJ) $(LIB.A) $(FLAGS)


%.o: %.c
		cc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(P_OBJ_NAME) $(SH_OBJ_NAME) $(LIB.A)
		make clean -C $(LIB)

fclean:		clean
		$(RM)  $(NAME_P) $(LIB.A)
		make fclean -C $(LIB)

re:		fclean all

.PHONY: 	all clean fclean re

#for linux
#gcc read_map.c read_map_util.c read_map_util_2.c so_long.c -Llibft libft.a -Lmlx_linux libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz
