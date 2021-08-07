#include "push_swap.h"

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

void	send_ele_from_a_to_b(int nb, int nb_to_b, int mid, t_stack *a, t_stack *b)
{
	while (nb_to_b)
	{
		while (nb_to_b && a->tab[a->top] < mid)
		{
			b->tab[++(b->top)] = a->tab[(a->top)--];
			ft_putstr_w_new_line("pb");
			nb_to_b--;
		}
		//check nb from bottom of chunk
		while (a->tab[a->top + 1 - nb_to_b] < mid && nb_to_b)
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
}


void	do_it(int nb_to_manage, t_stack *src, t_stack *dest)
{
	int	mid;
	int	nb_to_move;
	t_stack	*a;
	t_stack	*b;

	a = src->a_add;
	b = src->b_add;
	nb_to_move = 0;
	//move from b to a
	if (arr_is_sorted(a->lens - 1, a) && b->top == -1)//a is sorted and b is vide
		return ;
	if (src == a && (nb_to_manage < 3 || arr_is_sorted(nb_to_manage, a)))
		manage_a(nb_to_manage, a, b);
	else if (src == b && (nb_to_manage < 3 || arr_is_desending(nb_to_manage, b)))
		manage_b(nb_to_manage, a, b);
	else
	{
		if(!arr_is_sorted(nb_to_manage, a) || src == b)
		{
			nb_to_move = nb_to_group(nb_to_manage, src);
			mid = get_mid_nb(nb_to_manage, src);
			if (src == a)
				send_ele_from_a_to_b(nb_to_manage, nb_to_move, mid, a, b);
			else
				send_ele_from_b_to_a(nb_to_move, mid, b, a);
			if (!arr_is_sorted(nb_to_manage, a) || src == b)
				do_it(nb_to_manage - nb_to_move, src, dest);
		}
		do_it(nb_to_move, dest, src);
	}

}
