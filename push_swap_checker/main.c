#include "push_swap.h"

int	check_arg(t_stack *ptr)
{
	if (!isNumber(ptr) || has_extrem_nb(ptr)
		|| has_duplicates_arg(ptr))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		if (ptr->from_arg)
			ft_tabfree(ptr->arr);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (0);
	init_stack_a(ac, av, &a);
	if (check_arg(&a))
		return (0);
	init_stack_b(&a, &b);
	get_instruction_and_sort(&a, &b);
	free_stack(&a, &b);
//	 ARG="2 1 0" ; ./checker $ARG
}
