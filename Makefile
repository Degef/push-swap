# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 20:05:04 by Degef             #+#    #+#              #
#    Updated: 2023/03/21 17:13:45 by Degef            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

M_SRCS	= push_swap.c utils.c operations.c put_sorting_index.c validate_args.c count_moves.c \
			find_target.c sort_three.c send_to_b.c cost.c rearrange.c position.c adjust.c create_stack.c

FLAGS	= -Wall -Wextra -Werror
CC		= cc
RM		= rm -f 

M_OBJS	= $(M_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJS)
	cd ./libft && make
	$(CC) $(FLAGS) $(M_OBJS) ./libft/libft.a -o $(NAME)
	
clean: 
	cd ./libft && make clean
	$(RM) $(M_OBJS) 

fclean: clean
	cd ./libft && make fclean
	$(RM) $(NAME) 

re: fclean all