/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:35:05 by Degef             #+#    #+#             */
/*   Updated: 2023/03/21 17:44:58 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
		exit(0);
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

int	main(int argc, char **argv)
{
	t_node	*a;
	int		i;
	char	*storage;
	char	*str;

	if (argc >= 2)
	{
		i = 1;
		storage = NULL;
		if (!argv[i][0])
			handle_error(0);
		while (argv[i])
		{
			storage = ft_strjoin(storage, argv[i++]);
			storage = ft_strjoin(storage, " ");
		}
		if (!check_invalid_args(storage) || !check_dup(storage))
			handle_error(0);
		a = NULL;
		create_stack(&storage, &a);
		put_sorting_index(&a);
		push_swap(&a);
		free_linked_list(&a);
	}	
	return (0);
}

		// while (a)
		// {
		// 	printf("%d : %d\n", a->data, a->sort_index);
		// 	a = a->next;
		// }