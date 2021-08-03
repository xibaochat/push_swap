#include "push_swap.h"

int		arr_is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->tab[i] > a->tab[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int		nb_to_group(t_stack *ptr)
{
	int	lens;
	int	nb_to_group;

	lens = ptr->top + 1;
	if (lens % 2 == 0)
		nb_to_group = lens / 2;
	else
		nb_to_group = (lens - 1) / 2;
	return (nb_to_group);
}

void	reverse_and_pb(t_stack *a, t_stack *b)
{
	reverse_stack_tab(a);
	ft_putstr_w_new_line("rra");
	b->tab[++b->top] = a->tab[a->top--];
	ft_putstr_w_new_line("pb");
}

void	rotate_and_pb(int mid, int *n, t_stack *a, t_stack *b)
{
	rotate_stack_tab(a);
	ft_putstr_fd("je suis ici\n", 1);
	if (a->tab[a->top] < mid)
	{
		ft_putstr_w_new_line("ra");
		b->tab[++b->top] = a->tab[a->top--];
		ft_putstr_w_new_line("pb");
		(*n)--;
	}
}

void	send_ele_from_a_to_b(int mid, t_stack *a, t_stack *b)
{
	int	nb_to_b;

	if (a->top == 1)
		return ;
	nb_to_b = nb_to_group(a);
	while (nb_to_b)
	{
		while (a->tab[a->top] < mid && nb_to_b)
		{
			b->tab[++(b->top)] = a->tab[(a->top)--];
			ft_putstr_w_new_line("pb");
			nb_to_b--;
		}
		while (a->tab[0] < mid && nb_to_b)
		{
			reverse_and_pb(a, b);
			nb_to_b--;
		}
		while (a->tab[a->top] >= mid && nb_to_b)
		{
			rotate_stack_tab(a);
			ft_putstr_w_new_line("ra");
		}
		if (a->tab[a->top] < mid)
		{
			b->tab[++(b->top)] = a->tab[(a->top)--];
			ft_putstr_w_new_line("pb");
			nb_to_b--;
		}
	}
	ft_putstr_w_new_line("-----STACK A-----");
	show_arr_value3(a);
	ft_putstr_w_new_line("\n-----STACK B-----");
	show_arr_value3(b);
}

void	copy_tab(int *tmp, t_stack *a)
{
	int	i;

	i = -1;
	while (++i <= a->top)
		tmp[i] = a->tab[i];
}

void	do_push_swap(t_stack *a, t_stack *b)
{
	int	mid;
	int	*tmp;

	if (arr_is_sorted(a) || a->top == 1)
		return ;
	tmp = (int *)malloc(sizeof(int) * (a->top + 1));
	copy_tab(tmp, a);
	mid = sort_and_get_mid_nb(tmp, a->top + 1);
	send_ele_from_a_to_b(mid, a, b);
	free(tmp);
	if (!arr_is_sorted(a) && a->top != 1)
		do_push_swap(a, b);
}
