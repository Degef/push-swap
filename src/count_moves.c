/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:11 by Degef             #+#    #+#             */
/*   Updated: 2023/03/21 19:41:43 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_forward_moves(t_node *stack, int point)
{
	int	i;

	i = 0;
	while (stack->sort_index != point)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	count_backward_moves(t_node *stack, int point)
{
	int	i;

	i = 0;
	while (stack->sort_index != point)
		stack = stack->next;
	stack = stack->next;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i + 1);
}
