#include "push_swap.h"

void	init_two_stack(t_stack *a, t_stack *b)
{
	a->tab = transfer_char_to_int_of_arr(a);
	init_stack_b(a, b);
}

void	free_two_stack(t_stack *a, t_stack *b)
{
	if (a->from_arg)
        ft_tabfree(a->arr);
	if (a->tab)
    {
        free(a->tab);
        a->tab = NULL;
    }
	if (b->tab)
	{
		free(b->tab);
        b->tab = NULL;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (0);
	init_stack_a(ac, av, &a);
	if (check_arg(&a))
		return (0);
	init_two_stack(&a, &b);
	do_push_swap(&a, &b);
	free_two_stack(&a, &b);
	return (0);
}
