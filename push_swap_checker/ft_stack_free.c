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
