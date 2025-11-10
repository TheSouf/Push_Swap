/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:10:20 by sofkhali          #+#    #+#             */
/*   Updated: 2025/11/10 17:35:09 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		free_and_exit(a, b);
	if (!parse_args(argc, argv, a))
		free_and_exit(a, b);
	if (a->size == 0)
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (has_duplicates(a))
		free_and_exit(a, b);
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	index_stack(a);
	if (a->size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
