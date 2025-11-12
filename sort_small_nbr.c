/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:00:00 by sofkhali          #+#    #+#             */
/*   Updated: 2025/11/12 17:18:16 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_top_pos(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && first > third)
		return (0);
	if (second > first && second > third)
		return (1);
	return (2);
}

void	sort_three(t_stack *a)
{
	int	max_pos;

	if (is_sorted(a))
		return ;
	max_pos = ft_find_top_pos(a);
	if (max_pos == 0)
		ra(a, 1);
	else if (max_pos == 1)
		rra(a, 1);
	if (a->top->index > a->top->next->index)
		sa(a, 1);
}

static void	ft_rotate_to_top(t_stack *a, int target_index)
{
	int	pos;
	int	size;

	pos = get_position(a, target_index);
	size = a->size;
	if (pos <= size / 2)
	{
		while (a->top->index != target_index)
			ra(a, 1);
	}
	else
	{
		while (a->top->index != target_index)
			rra(a, 1);
	}
}

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int		min_index;
	t_node	*current;

	min_index = a->top->index;
	current = a->top;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	ft_rotate_to_top(a, min_index);
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (a->size == 4)
	{
		push_smallest_to_b(a, b);
		sort_three(a);
		pa(a, b);
	}
	else if (a->size == 5)
	{
		push_smallest_to_b(a, b);
		push_smallest_to_b(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
}
