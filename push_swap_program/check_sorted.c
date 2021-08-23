/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:26:49 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/10 14:36:24 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_is_sorted(int n, t_stack *ptr)
{
	int	i;

	i = ptr->top;
	while (i > ptr->top - n && i >= 1)
	{
		if (ptr->tab[i] > ptr->tab[i - 1])
			return (0);
		--i;
	}
	return (1);
}

int	arr_is_sorted(int n, t_stack *ptr)
{
	--n;
	while (n > 0)
	{
		if (ptr->tab[n] > ptr->tab[n - 1])
			return (0);
		--n;
	}
	return (1);
}

int	arr_is_desending(int n, t_stack *ptr)
{
	int	index;

	index = ptr->top;
	while (n > 1)
	{
		if (ptr->tab[index] < ptr->tab[index - 1])
			return (0);
		--n;
		--index;
	}
	return (1);
}
