/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:28 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/13 17:49:44 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_two_stack(t_stack *a, t_stack *b)
{
	if (a->top > 0)
		reverse_stack(a);
	if (b->top > 0)
		reverse_stack(b);
}
