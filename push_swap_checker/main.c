/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:28 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/21 15:01:48 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_b_in_checker(t_stack *a, t_stack *b)
{
	b->top = -1;
	b->lens = a->lens;
	b->from_arg = 0;
	b->arr = (char **)malloc(sizeof(char *) * (b->lens));
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1 || has_empty_arg(ac, av))
		return (0);
	init_stack_a(ac, av, &a);
	if (check_arg(&a))
		return (0);
	init_stack_b_in_checker(&a, &b);
	get_instruction_and_sort(&a, &b);
	return (0);
}
