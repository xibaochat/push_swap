/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:28 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/13 17:49:44 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swatch_value(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	swatch_two_stack(t_stack *a, t_stack *b)
{
	if (a->top > 0)
		swatch_value_tab(a->tab + (a->top), a->tab + (a->top - 1));
	if (b->top > 0)
		swatch_value_tab(b->tab + (b->top), a->tab + (b->top - 1));
}

void	rotate_stack(t_stack *stack)
{
	int	n;
	int	t;

	if (!stack)
		return ;
	n = stack->top;
	t = stack->tab[stack->top];
	while (--n >= 0)
		stack->tab[n + 1] = stack->tab[n];
	stack->tab[0] = t;
}

void	rotate_two_up(t_stack *a, t_stack *b)
{
	if (a->top > 0)
		rotate_stack(a);
	if (b->top > 0)
		rotate_stack(b);
}

void	reverse_stack(t_stack *a)
{
	int	i;
	int	tmp;

	tmp = a->tab[0];
	i = 1;
	while (i <= a->top)
	{
		a->tab[i - 1] = a->tab[i];
		i++;
	}
	a->tab[a->top] = tmp;
}
