/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:16:16 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/10 15:16:17 by xinwang          ###   ########.fr       */
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
		swatch_value(a->arr + (a->top), a->arr + (a->top - 1));
	if (b->top > 0)
		swatch_value(b->arr + (b->top), b->arr + (b->top - 1));
}

void	rotate_stack(t_stack *stack)
{
	int		n;
	char	*t;

	n = stack->top - 1;
	t = (stack)->arr[stack->top];
	while (n >= 0)
	{
		(stack)->arr[n + 1] = (stack)->arr[n];
		n--;
	}
	stack->arr[0] = t;
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
	int		i;
	char	*tmp;

	tmp = a->arr[0];
	i = 1;
	while (i <= a->top)
	{
		a->arr[i - 1] = a->arr[i];
		i++;
	}
	a->arr[a->top] = tmp;
}
