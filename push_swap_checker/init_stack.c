/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:28 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/23 17:31:48 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*transfer_char_to_int_of_arr(t_stack *stack)
{
	int	*tab;
	int	i;

	i = -1;
	tab = (int *)malloc(sizeof(int) * (stack->top + 1));
	while (++i < stack->top + 1)
		tab[i] = ft_atoi(stack->arr[i]);
	return (tab);
}

void	rverese_array(char **arr, int start, int end)
{
	char	*temp;

	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

void	init_stack_a(int ac, char **av, t_stack *ptr)
{
	int		lens;

	lens = get_nb_words_in_arr(av[1], 32);
	if (ac == 2 && lens >= 1)
	{
		ptr->from_arg = 1;
		ptr->lens = lens;
		ptr->arr = ft_split(av[1], 32);
	}
	else
	{
		ptr->from_arg = 0;
		ptr->lens = ac - 1;
		ptr->arr = av + 1;
	}
	rverese_array(ptr->arr, 0, ptr->lens - 1);
	ptr->tab = NULL;
	ptr->top = ptr->lens - 1;
}
