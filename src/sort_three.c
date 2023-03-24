/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:34:50 by Degef             #+#    #+#             */
/*   Updated: 2023/03/21 19:42:39 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->sort_index;
	second = (*stack)->next->sort_index;
	third = (*stack)->next->next->sort_index;
	if ((first < second) && (second < third))
		return ;
	else if ((first < second) && (first < third))
	{
		swap(*stack, "sa");
		rotate(stack, "ra", 1);
	}
	else if ((first > second) && (first < third) && (second < third))
		swap(*stack, "sa");
	else if ((first < second) && (first > third))
		reverse_rotate(stack, "rra", -1);
	else if ((first > second) && (first > third) && (second < third))
		rotate(stack, "ra", 1);
	else if ((first > second) && (first > third) && (second > third))
	{
		swap(*stack, "sa");
		reverse_rotate(stack, "rra", -1);
	}
}
