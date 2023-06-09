/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:29:20 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/24 14:42:54 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_storage(char ***storage, char **str)
{
	free_array(storage);
	free(*str);
	handle_error(0);
}

int	check_dup(char **str)
{
	char	**storage;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	storage = ft_split(*str, ' ');
	while (storage[i])
	{
		j = i + 1;
		while (storage[j])
		{
			len = ft_strlen(storage[i]);
			if (ft_strlen(storage[j]) > ft_strlen(storage[i]))
				len = ft_strlen(storage[j]);
			if (ft_strncmp(storage[i], storage[j], len) == 0)
				free_storage(&storage, str);
			j++;
		}
		i++;
	}
	free_array(&storage);
	return (1);
}

static int	is_valid(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ' || (c >= '0' && c <= '9')
		|| c == '-' || c == '+')
		return (1);
	else
		return (0);
}

static int	check_if_not_num(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!ft_strncmp(str, "0", i))
		return (0);
	else
	{
		if (!ft_atoi(str))
			return (1);
		return (0);
	}
}

int	check_invalid_args(char **str)
{
	int		i;
	char	**storage;

	i = 0;
	while ((*str)[i])
	{
		if (is_valid((*str)[i]))
			i++;
		else
		{
			free(*str);
			return (0);
		}
	}
	i = 0;
	storage = ft_split(*str, ' ');
	while (storage[i])
	{
		if (check_if_not_num(storage[i]))
			free_storage(&storage, str);
		i++;
	}
	free_array(&storage);
	return (1);
}
