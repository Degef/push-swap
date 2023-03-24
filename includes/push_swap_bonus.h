/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:56:10 by Degef             #+#    #+#             */
/*   Updated: 2023/03/24 14:46:11 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct t_list
{
	int				data;
	struct t_list	*next;
}					t_node;

//create stack
void	create_stack(char **storage, t_node **a);

// utils
t_node	*lstlast(t_node *lst);
int		is_sorted(t_node *stack);
void	handle_error(int nb);
void	free_array(char ***str);
void	free_linked_list(t_node **stack);

//validate_args
int		check_dup(char **str);
int		check_invalid_args(char **str);

// operations
void	swap(t_node *stack, char *str);
void	push(t_node **stack_1, t_node **stack_2, char *str);
void	rotate(t_node **stack, char *str, int cost);
void	reverse_rotate(t_node **stack, char *str, int cost);
void	push_a(t_node **stack_1, t_node **stack_2, char *str);
void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);
void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);

//checker
void	checker(t_node **a, t_node **b);
void	check_instructions(t_node **a, t_node **b, char *instructions, int i);

//do both bonus
void	swap_both(t_node **a, t_node **b, int cost_a, int cost_b);

#endif