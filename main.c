/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:10:20 by sofkhali          #+#    #+#             */
/*   Updated: 2025/10/31 13:10:34 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
t_stack *a;
t_stack *b;


if (argc < 2)
return (0);
a = NULL;
b = NULL;
if (!parse_args(&a, argv + 1))
{
write(2, "Error\n", 6);
free_stack(&a);
return (1);
}