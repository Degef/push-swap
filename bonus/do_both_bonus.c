/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_both_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:32:59 by Degef             #+#    #+#             */
/*   Updated: 2023/03/22 21:01:57 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b < 0 && cost_a < 0)
	{
		reverse_rotate(a, " ", -1);
		reverse_rotate(b, " ", -1);
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
		cost_a--;
		cost_b--;
	}
	rotate(a, "ra", cost_a);
	rotate(b, "rb", cost_b);
}

void	swap_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b > 0 && cost_a > 0)
	{
		swap(*a, " ");
		swap(*b, " ");
		cost_a--;
		cost_b--;
	}
}
