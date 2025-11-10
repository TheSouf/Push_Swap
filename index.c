/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:00:00 by sofkhali          #+#    #+#             */
/*   Updated: 2025/11/10 17:35:11 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *stack, int exclude)
{
	t_node	*current;
	int		min;
	int		found;

	current = stack->top;
	min = INT_MAX;
	found = 0;
	while (current)
	{
		if (current->index == -1 && current->value != exclude)
		{
			if (!found || current->value < min)
			{
				min = current->value;
				found = 1;
			}
		}
		current = current->next;
	}
	return (min);
}

static void	assign_index(t_stack *stack, int value, int index)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value && current->index == -1)
		{
			current->index = index;
			return ;
		}
		current = current->next;
	}
}

void	index_stack(t_stack *stack)
{
	int	i;
	int	min;
	int	prev_min;

	i = 0;
	prev_min = INT_MIN;
	while (i < stack->size)
	{
		min = find_min(stack, prev_min);
		assign_index(stack, min, i);
		prev_min = min;
		i++;
	}
}
