INCS		= includes
LIB			= libft
LIB.A		= libft.a
P_SRC		= src/big_sort.c src/main.c src/small_sort.c
SHARE_SRC 	= share/check_err.c share/creat_listd.c share/operation_1.c share/operation_2.c share/replace_by_ranking.c share/parse_list.c
P_OBJ_NAME	= $(P_SRC:.c=.o)
SH_OBJ_NAME	= $(SHARE_SRC:.c=.o)
NAME		= so_long
FLAGS		= -Wall -Wextra -Werror -I${INCS} -I.
ifeq (${DEBUG}, 1)
	FLAGS	+= -g
endif
		
all: $(NAME_P) 

$(LIB.A):
		make -C $(LIB)
		@mv $(LIB)/$(LIB.A) .

$(NAME): $(LIB.A) $(P_OBJ_NAME) $(SH_OBJ_NAME)
		gcc -o $@ $(P_OBJ_NAME) $(SH_OBJ_NAME) $(LIB.A) $(FLAGS)


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