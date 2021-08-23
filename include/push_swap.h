/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:49:28 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/20 23:46:30 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack	t_stack;
typedef struct s_stack
{
	int		from_arg;
	int		lens;
	char	**arr;
	int		*tab;
	int		top;
	t_stack	*a_add;
	t_stack	*b_add;
}				t_stack;

void	init_stack_a(int ac, char **av, t_stack *ptr);
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
int		check_arg(t_stack *ptr);
int		sort_and_get_mid_nb(int *tab, int n);
void	swatch_value_tab(int *s1, int *s2);
void	swatch_two_stack_tab(t_stack *a, t_stack *b);
void	rotate_stack_tab(t_stack *stack);
void	rotate_two_up_tab(t_stack *a, t_stack *b);
void	reverse_stack_tab(t_stack *a);
void	do_it(int nb, t_stack *src, t_stack *dest);
int		arr_is_sorted(int n, t_stack *a);
int		nb_to_group(int n, t_stack *ptr);
void	copy_tab(int n, int *tmp, t_stack *a);
void	swatch_when_stack_has_two_unsorted_element(t_stack *a);
void	swatch_b_when_stack_has_two_unsorted_element(t_stack *a);
int		get_mid_nb(int n, t_stack *ptr);
int		arr_is_desending(int n, t_stack *ptr);
void	move_all_ele_from_b_to_a(int n, t_stack *a, t_stack *b);
void	manage_a(int n, t_stack *a);
void	manage_b(int n, t_stack *a, t_stack *b);
void	send_ele_from_a_to_b(int nb_m, int mid, t_stack *a, t_stack *b);
void	send_ele_from_b_to_a(int n, int m, t_stack *b, t_stack *a);
void	sort_tab(int **tab, int n);
int		chunk_is_sorted(int n, t_stack *ptr);
void	lens_is_four(t_stack *a, t_stack *b);
void	lens_is_three(t_stack *a);
void	lens_is_five(t_stack *a, t_stack *b);
void	manage_small_nb(int n, t_stack *a, t_stack *b);
void	reverse_and_pb(t_stack *a, t_stack *b);
void	rotate_and_pb(int mid, int *n, t_stack *a, t_stack *b);
void	move_to_b(t_stack *a, t_stack *b);
int		get_max_nb_position(t_stack *a);
void	move_b_a_when_nb_is_small(int nb, int nb_m, int mid, t_stack *b);
int		*get_sorted_tab(int n, int n1, int m, t_stack *b);
int		has_empty_arg(int ac, char **av);

#endif
