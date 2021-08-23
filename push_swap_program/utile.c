/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:14:01 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/23 18:40:41 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_to_group(int n, t_stack *ptr)
{
	int	nb_to_group;

	if (n < 3)
		return (0);
	if (ptr == ptr->a_add)
	{
		if (n % 2 == 0)
			nb_to_group = n / 2;
		else
			nb_to_group = (n - 1) / 2;
	}
	else
	{
		if (n % 2 == 0)
			nb_to_group = (n - 1) / 2;
		else
			nb_to_group = n / 2;
	}
	return (nb_to_group);
}

void	copy_tab(int nb, int *tmp, t_stack *ptr)
{
	int	t;

	t = ptr->top;
	while (nb > 0)
		tmp[--nb] = ptr->tab[t--];
}

void	swatch_when_stack_has_two_unsorted_element(t_stack *a)
{
	if (a->tab[a->top] > a->tab[a->top - 1])
	{
		swatch_value_tab(&a->tab[a->top], &a->tab[a->top - 1]);
		ft_putstr_w_new_line("sa");
	}
}

void	swatch_b_when_stack_has_two_unsorted_element(t_stack *a)
{
	if (a->tab[a->top] < a->tab[a->top - 1])
	{
		swatch_value_tab(&a->tab[a->top], &a->tab[a->top - 1]);
		ft_putstr_w_new_line("sb");
	}
}

int	get_mid_nb(int nb, t_stack *ptr)
{
	int	*tmp;
	int	mid;

	tmp = (int *)malloc(sizeof(int) * nb);
	copy_tab(nb, tmp, ptr);
	mid = sort_and_get_mid_nb(tmp, nb);
	free(tmp);
	return (mid);
}
