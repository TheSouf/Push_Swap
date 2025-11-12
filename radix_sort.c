/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:00:00 by sofkhali          #+#    #+#             */
/*   Updated: 2025/11/12 17:16:47 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = stack->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	ft_process_bit(t_stack *a, t_stack *b, int bit)
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

	max_bits = ft_count_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		if (is_sorted(a))
			return ;
		ft_process_bit(a, b, bit);
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
