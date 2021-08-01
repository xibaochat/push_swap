/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:28 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/13 17:49:44 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	int		from_arg;
	int		lens;
	char	**arr;
	int		*tab;
	int		top;

}				t_stack;

void	init_stack_a(int ac, char **av, t_stack *ptr);
void	init_stack_b(t_stack *a, t_stack *b);
void	free_stack(t_stack *a, t_stack *b);
bool	isNumber(t_stack *ptr);
bool	has_extrem_nb(t_stack *ptr);
bool	has_duplicates_arg(t_stack *ptr);
void	get_instruction_and_sort(t_stack *a, t_stack *b);
int		has_invalid_instruction(char *line);
int		*transfer_char_to_int_of_arr(t_stack *s);
void	check_a_is_sorted(t_stack *a, t_stack *b);
void	swatch_value(char **s1, char **s2);
void	swatch_two_stack(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *stack);
void	rotate_two_up(t_stack *a, t_stack *b);
void	reverse_stack(t_stack *a);
void	reverse_two_stack(t_stack *a, t_stack *b);

#endif
