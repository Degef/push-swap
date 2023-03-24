/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:56:10 by Degef             #+#    #+#             */
/*   Updated: 2023/03/23 17:54:23 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct t_list
{
	int				data;
	int				sort_index;
	int				cost_a;
	int				cost_b;
	int				pos;
	struct t_list	*next;
}					t_node;

//push_swap
void	push_swap(t_node **a);

//cost 
void	find_cost(t_node **a, t_node **b);
int		find_cheapest(t_node **b);

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

// do both
void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);
void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);

// put sorting index
int		find_len(t_node *stack);
void	sort_int_array(int **tab, int size);
void	assign_index(int len, t_node **stack, int *sorted_list);
void	put_sorting_index(t_node **stack);
int		find_midpoint(t_node *stack);

// count moves
int		count_forward_moves(t_node *stack, int point);
int		count_backward_moves(t_node *stack, int point);

// find_target
int		get_target_index(t_node **a, t_node **b);
void	find_min_and_max(int *a_min, int *a_max, t_node *temp);
void	check_min_and_max_diff(int *min_pos_diff, int *max_diff,
			t_node **a, t_node **b);

//sort three
void	sort_three(t_node **stack);

//send_to_b
void	send_to_b_by_mid_point(t_node **a, t_node **b);
void	send_to_b(t_node **a, t_node **b, int *total_nodes_to_go);
int		find_midpt(t_node *stack);
void	push_to_b(t_node **a, t_node **b, int *i, int *total_nodes_to_go);

//rearrange 
void	rearrange_a(t_node **stack, int point);

//position
void	assign_position(t_node **a, t_node **b);

//adjust
void	adjust(int cheapest_pos, t_node **a, t_node **b);

//checker
void	checker(t_node **a, t_node **b);
void	check_instructions(t_node **a, t_node **b, char *instructions);

#endif