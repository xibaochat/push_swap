# include "push_swap.h"

int	*get_sorted_tab(int total_nb, int nb_m, int mid, t_stack *b)
{
	int	*tmp;
	int	i;
	int tmp_nb_m;

	tmp_nb_m = nb_m;
	i = b->top;
	tmp = (int *)malloc(sizeof(int) * nb_m);
	while (total_nb > 0)
	{
		if (b->tab[i] > mid)
		{
			--tmp_nb_m;
			tmp[tmp_nb_m] = b->tab[i];
		}
		--i;
		--total_nb;
	}
	sort_tab(&tmp, nb_m);
	return (tmp);
}
