/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:03:02 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/10 13:13:09 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_ele_from_a_to_b(int nb_m, int mid, t_stack *a, t_stack *b)
{
	int	n_rotation;

	n_rotation = 0;
	while (nb_m)
	{
		while (nb_m && a->tab[a->top] < mid)
		{
			++(b->top);
			b->tab[b->top] = a->tab[a->top];
			--(a->top);
			ft_putstr_w_new_line("pb");
			--nb_m;
		}
		while (a->tab[a->top] >= mid && nb_m)
		{
			rotate_stack_tab(a);
			ft_putstr_w_new_line("ra");
			++n_rotation;
		}
	}
	while (n_rotation-- > 0)
	{
		reverse_stack(a);
		ft_putstr_w_new_line("rra");
	}
}
