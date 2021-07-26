#include "push_swap.h"

void	init_stack(int ac, char **av, t_stack *ptr)
{
	ptr->from_arg = 0;
	ptr->lens = ac - 1;
	ptr->arr = av + 1;
}
