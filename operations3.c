/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:00:00 by sofkhali          #+#    #+#             */
/*   Updated: 2025/11/08 20:00:31 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int print)
{
	t_node	*last;
	t_node	*before_last;

	if (!a || !a->top || !a->top->next)
		return ;
	last = a->top;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	last->next = a->top;
	a->top = last;
	before_last->next = NULL;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int print)
{
	t_node	*last;
	t_node	*before_last;

	if (!b || !b->top || !b->top->next)
		return ;
	last = b->top;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	last->next = b->top;
	b->top = last;
	before_last->next = NULL;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
