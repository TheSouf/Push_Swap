/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:29:34 by sofkhali          #+#    #+#             */
/*   Updated: 2025/11/10 17:35:01 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_number(t_stack *a, char *str)
{
	long	num;
	t_node	*node;

	if (!is_valid_number(str))
		return (0);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	node = create_node((int)num);
	if (!node)
		return (0);
	push_node(a, node);
	return (1);
}

static int	parse_single_arg(t_stack *a, char *arg)
{
	char	**split;
	int		i;
	int		success;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
	{
		if (split)
			free_split(split);
		return (0);
	}
	i = 0;
	while (split[i])
	{
		success = add_number(a, split[i]);
		if (!success)
		{
			free_split(split);
			return (0);
		}
		i++;
	}
	free_split(split);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	int	i;

	if (argc == 2)
		return (parse_single_arg(a, argv[1]));
	i = 1;
	while (i < argc)
	{
		if (!add_number(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
