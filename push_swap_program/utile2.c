/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:13:35 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/23 18:10:49 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack *a, t_stack *b)
{
	b->tab[++b->top] = a->tab[a->top--];
	ft_putstr_w_new_line("pb");
}

int	get_max_nb_position(t_stack *a)
{
	int	i;
	int	max;
	int	p;

	i = a->top;
	p = i;
	max = a->tab[i];
	while (i >= 0)
	{
		if (a->tab[i] > max)
		{
			max = a->tab[i];
			p = i;
		}
		--i;
	}
	return (p);
}

void	reverse_and_pb(t_stack *a, t_stack *b)
{
	reverse_stack_tab(a);
	ft_putstr_w_new_line("rra");
	b->tab[++b->top] = a->tab[a->top--];
	ft_putstr_w_new_line("pb");
}

void	rotate_and_pb(int mid, int *n, t_stack *a, t_stack *b)
{
	rotate_stack_tab(a);
	if (a->tab[a->top] < mid)
	{
		ft_putstr_w_new_line("ra");
		++(b->top);
		b->tab[b->top] = a->tab[a->top];
		--(a->top);
		ft_putstr_w_new_line("pb");
		--(*n);
	}
}

int	*get_sorted_tab(int total_nb, int nb_m, int mid, t_stack *b)
{
	int	*tmp;
	int	i;
	int	tmp_nb_m;

	tmp_nb_m = nb_m;
	i = b->top;
	tmp = (int *)malloc(sizeof(int) * nb_m);
	while (total_nb > 0)
	{
		if (b->tab[i] > mid)
		{
			--tmp_nb_m;
			tmp[tmp_nb_m] = b->tab[i];
		}
		--i;
		--total_nb;
	}
	sort_tab(&tmp, nb_m);
	return (tmp);
}
