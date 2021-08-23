/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction_and_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:28 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/21 14:55:02 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_arr_value2(t_stack *stack)
{
	int	n;

	n = stack->top;
	while (n > -1)
		ft_putstr_w_new_line(stack->arr[n--]);
}

void	show_arr_value3(t_stack *stack)
{
	int	n;

	n = stack->top;
	while (n > -1)
	{
		ft_putnbr_fd(stack->tab[n--], 1);
		ft_putstr_fd("\n", 1);
	}
}

void	do_instruction(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "sa") && a->top > 0)
		swatch_value(a->arr + (a->top), a->arr + (a->top - 1));
	else if (!ft_strcmp(line, "sb") && b->top > 0)
		swatch_value(b->arr + (b->top), b->arr + (b->top - 1));
	else if (!ft_strcmp(line, "ss"))
		swatch_two_stack(a, b);
	else if (!ft_strcmp(line, "pa") && b->top > -1)
		a->arr[++a->top] = b->arr[b->top--];
	else if (!ft_strcmp(line, "pb") && a->top > -1)
		b->arr[++b->top] = a->arr[a->top--];
	else if (!ft_strcmp(line, "ra") && a->top > 0)
		rotate_stack(a);
	else if (!ft_strcmp(line, "rb") && b->top > 0)
		rotate_stack(b);
	else if (!ft_strcmp(line, "rr"))
		rotate_two_up(a, b);
	else if (!ft_strcmp(line, "rra") && a->top > 0)
		reverse_stack(a);
	else if (!ft_strcmp(line, "rrb") && b->top > 0)
		reverse_stack(b);
	else if (!ft_strcmp(line, "rrr"))
		reverse_two_stack(a, b);
}

void	get_instruction_and_sort(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (line && !line[0])
		{
			free(line);
			check_a_is_sorted(a, b);
			return ;
		}
		if (has_invalid_instruction(line))
		{
			free(line);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			free_stack(a, b);
			exit(0);
		}
		do_instruction(a, b, line);
		free(line);
	}
	check_a_is_sorted(a, b);
	if (line)
		free(line);
}
