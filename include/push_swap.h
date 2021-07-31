#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct	s_stack
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

#endif
