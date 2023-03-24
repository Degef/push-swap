/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:11:31 by Degef             #+#    #+#             */
/*   Updated: 2023/03/24 14:30:39 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_dup2(t_node **a, long num)
{
	t_node	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->data == (int)num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void	free_stuff(int num, t_node **a, char ***str)
{
	if (num > INT_MAX || num < INT_MIN || check_dup2(a, num))
	{
		free_linked_list(a);
		free_array(str);
		handle_error(0);
	}
}

void	create_stack(char **storage, t_node **a)
{
	t_node	*nod;
	long	num;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(*storage, ' ');
	free(*storage);
	while (str[i])
	{
		num = ft_atoi(str[i]);
		free_stuff(num, a, &str);
		nod = malloc(sizeof(t_node));
		nod->data = num;
		nod->next = NULL;
		nod->sort_index = 0;
		if (!*a)
			(*a) = nod;
		else
			lstlast(*a)->next = nod;
		i++;
	}
	free_array(&str);
}
