/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:16:47 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/21 20:28:56 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a, t_stack *b)
{
	if (a)
	{
		if (a->from_arg)
			ft_tabfree(a->arr);
		if (a->tab)
		{
			free(a->tab);
			a->tab = NULL;
		}
		a = NULL;
	}
	if (b)
	{
		free(b->arr);
		b = NULL;
	}
}
