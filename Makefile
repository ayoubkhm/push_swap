NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -I ./include/push_swap.h

SRC =	./src/stack_utils/liste_chainee.c  \
		./src/stack_utils/liste_chainee_insertion.c  \
		main.c \
		./src/parsing/parsing.c \
		./src/parsing/parsing_utils.c \
		./src/sorting/sort_big_stack.c \
		./src/sorting/sort_small_stack.c \
		./src/stack_utils/stack_utils.c \
		./src/stack_utils/stack_utils_sorting.c \
		./src/stack_utils/operations.c \
		./src/sorting/sort_list_of_three.c \
		./src/sorting/sort_list_of_four.c \
		./src/sorting/sort_list_of_five.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

LIB = ./libft/

LIB_FILE = $(LIB)libft.a

$(LIB_FILE) :
	make -C $(LIB) 

$(NAME) : $(LIB_FILE) $(OBJ) ./include/push_swap.h Makefile
	clang $(CFLAGS) -o $(NAME) -Ilibft $(OBJ) $(LIB_FILE) 

clean :
	rm -rf $(OBJ)
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
