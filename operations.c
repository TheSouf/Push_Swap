/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:11:01 by sofkhali          #+#    #+#             */
/*   Updated: 2025/11/08 20:00:27 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int print)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	temp = first->index;
	first->index = second->index;
	second->index = temp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	temp = first->index;
	first->index = second->index;
	second->index = temp;
	if (print)
		write(1, "sb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!b || !b->top)
		return ;
	temp = b->top;
	b->top = b->top->next;
	b->size--;
	temp->next = a->top;
	a->top = temp;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!a || !a->top)
		return ;
	temp = a->top;
	a->top = a->top->next;
	a->size--;
	temp->next = b->top;
	b->top = temp;
	b->size++;
	write(1, "pb\n", 3);
}
