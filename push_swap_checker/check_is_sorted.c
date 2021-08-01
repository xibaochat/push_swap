/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <pnielly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:28 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/13 17:49:44 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_a_is_sorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (a->top + 1 == a->lens && b->top == -1)
	{
		a->tab = transfer_char_to_int_of_arr(a);
		while (i < a->top)
		{
			if (a->tab[i] < a->tab[i + 1])
			{
				ft_putstr_fd("KO\n", STDERR_FILENO);
				free(a->tab);
				exit(0);
			}
			i++;
		}
		ft_putstr_fd("OK\n", 1);
	}
	else
	{
		ft_putstr_fd("KO\n", STDERR_FILENO);
		exit(0);
	}
}
