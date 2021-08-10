/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:25:59 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/10 14:17:27 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_chunk(int *tab, int nb_to_manage, int top)
{
	int	j;
	int	k;

	j = top;
	k = 0;
	while (k++ < nb_to_manage)
		ft_putstr_w_new_line(ft_itoa(tab[j--]));
}

void	do_mid_value_algo(int nb_to_manage, int nb_m, int mid, t_stack *src)
{
	t_stack	*a;
	t_stack	*b;

	a = src->a_add;
	b = src->b_add;
	if (src == a)
		send_ele_from_a_to_b(nb_m, mid, a, b);
	else if (nb_m <= 3)
		move_b_a_when_nb_is_small(nb_to_manage, nb_m, mid, b);
	else
		send_ele_from_b_to_a(nb_m, mid, b, a);
}

int	still_need_to_use_algo(t_stack *src, int nb, int nb_m)
{
	if ((src == src->a_add && !chunk_is_sorted(nb - nb_m, src->a_add))
		|| (src == src->b_add && nb_m <= 3))
		return (1);
	return (0);
}

void	do_it(int nb_to_manage, t_stack *src, t_stack *dest)
{
	int		mid;
	int		nb_to_move;

	nb_to_move = 0;
	if (src == src->a_add && nb_to_manage < 3)
		manage_a(nb_to_manage, src->a_add);
	else if (src == src->b_add && (nb_to_manage < 3
			|| arr_is_desending(nb_to_manage, src->b_add)))
		manage_b(nb_to_manage, src->a_add, src->b_add);
	else
	{
		if (!chunk_is_sorted(nb_to_manage, src->a_add) || (src == src->b_add))
		{
			mid = get_mid_nb(nb_to_manage, src);
			nb_to_move = nb_to_group(nb_to_manage, src);
			do_mid_value_algo(nb_to_manage, nb_to_move, mid, src);
			if (still_need_to_use_algo(src, nb_to_manage, nb_to_move))
				do_it(nb_to_manage - nb_to_move, src, dest);
		}
		do_it(nb_to_move, dest, src);
		if (src == src->b_add && nb_to_move > 3)
			do_it(nb_to_manage - nb_to_move, src, dest);
	}
}
