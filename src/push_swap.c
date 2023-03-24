/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:35:05 by Degef             #+#    #+#             */
/*   Updated: 2023/03/24 14:42:42 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_a(t_node **a, t_node **b)
{
	int	cheapest_pos;

	while (*b)
	{
		assign_position(a, b);
		find_cost(a, b);
		cheapest_pos = find_cheapest(b);
		adjust(cheapest_pos, a, b);
		push(a, b, "pa");
	}
}

// This is a big functin which calls other main functions. It will first 
// 1. check if the stack is sorted 
// 2. check if the stack number if 2 and do the sorting 
// 3. check if the stack number is 3 and do the sorting 
// 4. send all number to stack b using the mid point algorithm 
//    if stack_a is bigger than 3
// 5. sort the three that are left in a 
// 6. call a function that will send the items from b to a by sorting 
// 7. finally rearrange the stack
void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
	{
		free_linked_list(a);
		exit(0);
	}
	else if (find_len(*a) == 2)
		swap(*a, "sa");
	else if (find_len(*a) == 3)
		sort_three(a);
	else if (find_len(*a) > 3)
	{
		send_to_b_by_mid_point(a, &b);
		sort_three(a);
	}
	push_to_a(a, &b);
	rearrange_a(a, 0);
	free_linked_list(&b);
	return ;
}

/*MY ALGORITHM*/
/*
1. I first joined all the contents inserted into one string separating by space. 
2. Then I chech if there is any invalid argument, which can be letter or anything outside number 
3. Then I check if there is duplicates and exit the program 
4. Then I create stack a based on the given numbers 
5. I partially used radix sorting technique. So I assign an index to each node in my stack. The index value is 
	the position that the specfic node should be place if they were sorted. So, now I can totally forget about the 
	real values and work only with the index number that I assigned. 

THE SORTING ALGORITHM SORTING STARTS FROM HERE
1. I check if the stack is already sorted. If so, simply exit else continue.  
2. check if the stack has two numbers. If so, do sa and exit. 
3. check if the stack has three numbers. If so, call the three numbers sorting 
   function and do the sorting. else continue
4. If stack_a has more than 3 elements then leave three items in stack_a and 
	send everything to stack_b using mid_point algorithm. Once all the elements 
	what are less than the first mid point are gone, we apply mid point algorith
	to the remaining onse. 
	**the mid point algorithm find mean(mid pt) of stack a and send all that are less than it to b
	**if the top is not less than a, send it to back using ra. 
5. Once only three elements are left on stack a, we will sort them using the three number sorting function. 
THE HIGHEST SORTING STARTS FROM HERE
while stack_b is not empty the following tasks will be repeated sequencailly
	1. find the current position of each element on stack a and stack b.
	2. Find total cost of putting the element to its position back in stack_a. which the cost of bringing the element to top of b
	   and the cost of find the position of the element in a and changing its position to be at the top of stack_a.
	3. So, now we have the costs of all the elements in b. Now we select the element with the list cost. 
*/

static char	*create_string_from_args(char **argv, char **storage)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
		{	
			free(*storage);
			handle_error(0);
		}
		*storage = ft_strjoin(*storage, argv[i++]);
		*storage = ft_strjoin(*storage, " ");
	}
	return (*storage);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	char	*storage;

	if (argc >= 2)
	{
		storage = NULL;
		storage = create_string_from_args(argv, &storage);
		if (!check_invalid_args(&storage) || !check_dup(&storage))
			handle_error(0);
		a = NULL;
		create_stack(&storage, &a);
		put_sorting_index(&a);
		push_swap(&a);
		free_linked_list(&a);
	}	
	return (0);
}
