/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_small_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:16:15 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/23 21:00:40 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_max_nb_to_b(int p, t_stack *a, t_stack *b)
{
	if (p == 3)
	{
		b->tab[++b->top] = a->tab[a->top--];
		ft_putstr_w_new_line("pb");
	}
	else if (p == 2)
	{
		swatch_value_tab(&a->tab[a->top], &a->tab[a->top - 1]);
		ft_putstr_w_new_line("sa");
		move_to_b(a, b);
	}
	else
	{
		while (p >= 0)
		{
			reverse_stack(a);
			ft_putstr_w_new_line("rra");
			--p;
		}
		move_to_b(a, b);
	}
}

void	lens_is_four(t_stack *a, t_stack *b)
{
	int	p;

	p = get_max_nb_position(a);
	move_max_nb_to_b(p, a, b);
	lens_is_three(a);
	a->tab[++a->top] = b->tab[b->top--];
	ft_putstr_w_new_line("pa");
	rotate_stack(a);
	ft_putstr_w_new_line("ra");
}

void	move_max_to_b(t_stack *a, t_stack *b)
{
	int	p;
	int	i;
	int	t;

	t = 0;
	p = get_max_nb_position(a);
	i = a->top;
	if (p > (a->top / 2))
	{
		t = i - p;
		while (t-- > 0)
		{
			rotate_stack(a);
			ft_putstr_w_new_line("ra");
		}
	}
	else
	{
		while (p-- >= 0)
		{
			reverse_stack(a);
			ft_putstr_w_new_line("rra");
		}
	}
	move_to_b(a, b);
}

void	lens_is_five(t_stack *a, t_stack *b)
{
	move_max_to_b(a, b);
	lens_is_four(a, b);
	a->tab[++a->top] = b->tab[b->top--];
	ft_putstr_w_new_line("pa");
	rotate_stack(a);
	ft_putstr_w_new_line("ra");
}
