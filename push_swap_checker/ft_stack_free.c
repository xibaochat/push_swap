/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:16:47 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/10 15:16:48 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a, t_stack *b)
{
	if (a->from_arg)
		ft_tabfree(a->arr);
	if (a->tab)
	{
		free(a->tab);
		a->tab = NULL;
	}
	if (b->arr && b->top != -1)
		ft_tabfree(b->arr);
	else
		free(b->arr);
}
