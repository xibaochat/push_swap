#include "push_swap.h"

void	check_arg(t_stack *ptr)
{
	if (!isNumber(ptr) || has_extrem_nb(ptr)
		|| has_duplicates_arg(ptr))
		ft_putstr_fd("Error\n", STDERR_FILENO);
}

int		main(int ac, char **av)
{
	char	**arr;
	t_stack	a;

	if (ac <= 1)
		return (0);
	init_stack(ac, av, &a);
	if (ac == 2)
	{
		a.arr = ft_split(av[1], 32);
		a.from_arg = 1;
		a.lens = get_nb_words_in_arr(av[1], 32);
		show_arr_value(a.arr);
	}
	check_arg(&a);
	if (a.from_arg)
		ft_tabfree(a.arr);
//	 ARG="2 1 0" ; ./checker $ARG
}
