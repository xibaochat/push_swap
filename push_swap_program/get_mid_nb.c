/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mid_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:01:07 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/20 23:25:44 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	sort_tab(int	**tab, int n)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if ((*tab)[j] < (*tab)[min_idx])
				min_idx = j;
			j++;
		}
		swap((*tab) + min_idx, (*tab) + i);
		i++;
	}
}

int	sort_and_get_mid_nb(int *tab, int n)
{
	int	mid;

	sort_tab(&tab, n);
	mid = tab[n / 2];
	return (mid);
}
