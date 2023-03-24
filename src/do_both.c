/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:32:59 by Degef             #+#    #+#             */
/*   Updated: 2023/03/22 20:33:39 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b < 0 && cost_a < 0)
	{
		reverse_rotate(a, " ", -1);
		reverse_rotate(b, " ", -1);
		write(1, "rrr\n", 4);
		cost_a++;
		cost_b++;
	}
	reverse_rotate(a, "rra", cost_a);
	reverse_rotate(b, "rrb", cost_b);
}

void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b > 0 && cost_a > 0)
	{
		rotate(a, " ", 1);
		rotate(b, " ", 1);
		write(1, "rr\n", 3);
		cost_a--;
		cost_b--;
	}
	rotate(a, "ra", cost_a);
	rotate(b, "rb", cost_b);
}
