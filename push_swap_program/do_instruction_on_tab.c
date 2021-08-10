/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:28 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/10 12:21:56 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swatch_value_tab(int *s1, int *s2)
{
	int	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	swatch_two_stack_tab(t_stack *a, t_stack *b)
{
	if (a->top > 0)
		swatch_value_tab(a->tab + (a->top), a->tab + (a->top - 1));
	if (b->top > 0)
		swatch_value_tab(b->tab + (b->top), a->tab + (b->top - 1));
}

void	rotate_stack_tab(t_stack *stack)
{
	int		n;
	int		t;

	n = stack->top - 1;
	t = stack->tab[stack->top];
	while (n >= 0)
	{
		stack->tab[n + 1] = stack->tab[n];
		n--;
	}
	stack->tab[0] = t;
}

void	rotate_two_up_tab(t_stack *a, t_stack *b)
{
	if (a->top > 0)
		rotate_stack(a);
	if (b->top > 0)
		rotate_stack(b);
}

void	reverse_stack_tab(t_stack *a)
{
	int		i;
	int		tmp;

	tmp = a->tab[0];
	i = 1;
	while (i <= a->top)
	{
		a->tab[i - 1] = a->tab[i];
		i++;
	}
	a->tab[a->top] = tmp;
}
