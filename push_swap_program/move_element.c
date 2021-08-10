/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:29:41 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/10 14:20:16 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_all_ele_from_b_to_a(int n, t_stack *a, t_stack *b)
{
	while (n-- > 0)
	{
		a->tab[++a->top] = b->tab[b->top--];
		ft_putstr_w_new_line("pa");
	}
}

void	manage_b(int n, t_stack *a, t_stack *b)
{
	if (n == 2)
		swatch_b_when_stack_has_two_unsorted_element(b);
	if (arr_is_desending(n, b))
	{
		while (n-- > 0)
		{
			a->tab[++a->top] = b->tab[b->top--];
			ft_putstr_w_new_line("pa");
		}
	}
}

void	manage_a(int n, t_stack *a)
{
	if (n == 2)
		swatch_when_stack_has_two_unsorted_element(a);
}

void	move_b_a_when_nb_is_small(int nb, int nb_m, int mid, t_stack *b)
{
	int		*sorted_tab;
	t_stack	*a;
	int		t;

	t = 0;
	a = b->a_add;
	sorted_tab = get_sorted_tab(nb, nb_m, mid, b);
	while (--nb_m >= 0)
	{
		while (b->tab[b->top] != sorted_tab[nb_m])
		{
			rotate_stack(b);
			ft_putstr_w_new_line("rb");
			t++;
		}
		a->tab[++(a->top)] = b->tab[b->top--];
		ft_putstr_w_new_line("pa");
		while (t > 0)
		{
			reverse_stack(b);
			ft_putstr_w_new_line("rrb");
			--t;
		}
	}
	free(sorted_tab);
}

void	send_ele_from_b_to_a(int nb_to_move, int mid, t_stack *b, t_stack *a)
{
	int	t;

	t = 0;
	while (nb_to_move)
	{
		while (nb_to_move && b->tab[b->top] > mid)
		{
			a->tab[++(a->top)] = b->tab[b->top--];
			ft_putstr_w_new_line("pa");
			nb_to_move--;
		}
		while (nb_to_move && b->tab[b->top] <= mid)
		{
			rotate_stack(b);
			ft_putstr_w_new_line("rb");
			++t;
		}
	}
	while (t > 0)
	{
		reverse_stack(b);
		ft_putstr_w_new_line("rrb");
		--t;
	}
}
