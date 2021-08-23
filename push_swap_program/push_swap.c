/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:20:55 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/23 20:30:18 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lens_is_three(t_stack *a)
{
	if ((a->tab[a->top] > a->tab[a->top - 1])
		&& (a->tab[a->top] > a->tab[a->top - 2]))
	{
		rotate_stack(a);
		ft_putstr_w_new_line("ra");
		swatch_when_stack_has_two_unsorted_element(a);
	}
	else if ((a->tab[a->top] < a->tab[a->top - 1])
		&& (a->tab[a->top - 1] > a->tab[a->top - 2]))
	{
		reverse_stack(a);
		ft_putstr_w_new_line("rra");
		swatch_when_stack_has_two_unsorted_element(a);
	}
	else
		swatch_when_stack_has_two_unsorted_element(a);
}

void	manage_small_nb(int n, t_stack *a, t_stack *b)
{
	if (n == 1)
		return ;
	else if (n == 2)
		 swatch_when_stack_has_two_unsorted_element(a);
	else if (n == 3)
		lens_is_three(a);
	else if (n == 4)
		lens_is_four(a, b);
	else
		lens_is_five(a, b);
}

void	init_two_stack(t_stack *a, t_stack *b)
{
	a->tab = transfer_char_to_int_of_arr(a);
	b->top = -1;
	b->lens = a->lens;
	b->from_arg = 0;
	b->tab = (int *)malloc(sizeof(int) * (b->lens));
	a->a_add = a;
	a->b_add = b;
	b->a_add = a;
	b->b_add = b;
}

void	free_two_stack(t_stack *a, t_stack *b)
{
	if (a->from_arg)
		ft_tabfree(a->arr);
	if (a->tab)
	{
		free(a->tab);
		a->tab = NULL;
	}
	if (b->tab)
	{
		free(b->tab);
		b->tab = NULL;
	}
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
	init_two_stack(&a, &b);
	if (arr_is_sorted(a.lens, &a))
	{
		free_two_stack(&a, &b);
		return (0);
	}
	if (a.lens <= 5)
	{
		manage_small_nb(a.lens, &a, &b);
		free_two_stack(&a, &b);
		return (0);
	}
	do_it(a.lens, &a, &b);
	free_two_stack(&a, &b);
	return (0);
}
