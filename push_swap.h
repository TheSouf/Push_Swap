/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:10:59 by sofkhali          #+#    #+#             */
/*   Updated: 2025/11/10 18:36:57 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b);

int		ft_atoi(char *str);
char	**ft_split(char const *s, char c);
int		parse_args(int argc, char **argv, t_stack *a);
int		is_valid_number(char *str);
long	ft_atol(char *str);

t_stack	*init_stack(void);
t_node	*create_node(int value);
void	push_node(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);
void	free_split(char **split);
int		get_position(t_stack *stack, int index);

int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);

void	index_stack(t_stack *stack);

void	radix_sort(t_stack *a, t_stack *b);
int		get_max_bits(t_stack *stack);

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

void	error_exit(void);
void	free_and_exit(t_stack *a, t_stack *b);

#endif
