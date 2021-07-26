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



}				t_stack;

void	init_stack(int ac, char **av, t_stack *ptr);
void	ft_tabfree(char **tab);
bool	isNumber(t_stack *ptr);
bool	has_extrem_nb(t_stack *ptr);
bool	has_duplicates_arg(t_stack *ptr);

#endif
