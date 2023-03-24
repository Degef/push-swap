/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rearrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:00:27 by Degef             #+#    #+#             */
/*   Updated: 2023/03/21 19:42:25 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rearrange_a(t_node **stack, int point)
{
	int	ra_size;
	int	rra_size;

	ra_size = count_forward_moves(*stack, point);
	rra_size = count_backward_moves(*stack, point);
	if (ra_size == 0)
		return ;
	else if (ra_size > rra_size)
		while (rra_size--)
			reverse_rotate(stack, "rra", -1);
	else
		while (ra_size--)
			rotate(stack, "ra", 1);
}
