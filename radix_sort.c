/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:00:00 by sofkhali          #+#    #+#             */
/*   Updated: 2025/11/10 17:34:56 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = stack->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_iteration(t_stack *a, t_stack *b, int bit)
{
	int		size;
	int		i;
	t_node	*top;

	size = a->size;
	i = 0;
	while (i < size)
	{
		top = a->top;
		if (((top->index >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a, 1);
		i++;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;

	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		if (is_sorted(a))
			return ;
		radix_iteration(a, b, bit);
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
