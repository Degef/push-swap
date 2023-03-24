CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap
C_NAME = checker

SRC_PATH = src/
C_SRC_PATH = bonus/
OBJ_PATH = obj/

SRC		= push_swap.c utils.c operations.c put_sorting_index.c validate_args.c \
		 count_moves.c find_target.c sort_three.c send_to_b.c cost.c \
		  rearrange.c position.c adjust.c create_stack.c do_both.c

C_SRC	= checker_bonus.c create_stack_bonus.c validate_args_bonus.c operations_bonus.c \
			utils_bonus.c do_both_bonus.c

# SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

# C_SRCS	= $(addprefix $(C_SRC_PATH), $(C_SRC))
C_OBJ	= $(C_SRC:.c=.o)
C_OBJS	= $(addprefix $(OBJ_PATH), $(C_OBJ))


all: $(OBJ_PATH) $(NAME)

bonus: $(OBJ_PATH) $(C_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH)%.o: $(C_SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	cd ./libft && make
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

$(C_NAME): $(C_OBJS)
	cd ./libft && make
	$(CC) $(CFLAGS) $(C_OBJS) ./libft/libft.a -o $(C_NAME)

clean:
	cd ./libft && make fclean
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME) $(C_NAME)

re: fclean all