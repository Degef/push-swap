/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:40:05 by Degef             #+#    #+#             */
/*   Updated: 2023/03/24 15:17:32 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	checker(t_node **a, t_node **b)
{
	char	*ins;
	int		i;

	ins = ft_strdup("0");
	while (ins)
	{
		if (ins)
			free(ins);
		ins = get_next_line(0);
		if (ins)
			i = ft_strlen(ins - 1);
		if (ins)
			check_instructions(a, b, ins, i);
	}
	if (is_sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static int	do_both(t_node **a, t_node **b, char *ins, int i)
{
	if (!ft_strncmp(ins, "rr", i))
		rotate_both(a, b, 1, 1);
	else if (!ft_strncmp(ins, "rrr", i))
		reverse_rotate_both(a, b, -1, -1);
	else if (!ft_strncmp(ins, "ss", i))
		swap_both(a, b, 1, 1);
	else
		return (0);
	return (1);
}

void	check_instructions(t_node **a, t_node **b, char *ins, int i)
{
	if (ins)
	{
		if (!ft_strncmp(ins, "sa", i))
			swap(*a, " ");
		else if (!ft_strncmp(ins, "sb", i))
			swap(*b, " ");
		else if (!ft_strncmp(ins, "pa", i))
			push(a, b, " ");
		else if (!ft_strncmp(ins, "pb", i))
			push(b, a, " ");
		else if (!ft_strncmp(ins, "ra", i))
			rotate(a, " ", 1);
		else if (!ft_strncmp(ins, "rb", i))
			rotate(b, " ", 1);
		else if (!ft_strncmp(ins, "rra", i))
			reverse_rotate(a, " ", -1);
		else if (!ft_strncmp(ins, "rrb", i))
			reverse_rotate(b, " ", -1);
		else if (do_both(a, b, ins, i))
			return ;
		else
			handle_error(0);
	}
}

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
	t_node	*b;
	char	*storage;

	if (argc >= 2)
	{
		storage = NULL;
		storage = create_string_from_args(argv, &storage);
		if (!check_invalid_args(&storage) || !check_dup(&storage))
			handle_error(0);
		a = NULL;
		b = NULL;
		create_stack(&storage, &a);
		checker(&a, &b);
		free_linked_list(&a);
	}	
	return (0);
}
