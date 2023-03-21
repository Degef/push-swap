/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:02:45 by Degef             #+#    #+#             */
/*   Updated: 2023/03/21 17:02:51 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_position(t_node **a, t_node **b)
{
	int		i;
	t_node	*temp1;
	t_node	*temp2;

	i = 0;
	temp1 = *a;
	temp2 = *b;
	while (temp1)
	{
		temp1->pos = i++;
		temp1 = temp1->next;
	}
	i = 0;
	while (temp2)
	{
		temp2->pos = i++;
		temp2 = temp2->next;
	}
}
