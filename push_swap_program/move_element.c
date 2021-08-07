#include "push_swap.h"

int		arr_is_sorted(int n, t_stack *ptr)
{
	n--;
	while (n > 0 && ptr->tab[n] && ptr->tab[n - 1])
	{
		if (ptr->tab[n] > ptr->tab[n - 1])
			return (0);
		n--;
	}
	return (1);
}

int		arr_is_desending(int n, t_stack *ptr)
{
	int	index;

	index = ptr->top;
	while (n > 1 && ptr->tab[index] && ptr->tab[index - 1])
	{
		if (ptr->tab[index] < ptr->tab[index - 1])
			return (0);
		n--;
		index--;
	}
	return (1);
}

void	move_all_ele_from_b_to_a(int n, t_stack *a, t_stack *b)
{
	while (n-- > 0)
	{
		a->tab[++a->top] = b->tab[b->top--];
		ft_putstr_w_new_line("pa");
	}
}

void	manage_b(int n, t_stack *a,  t_stack *b)
{
	if (n == 2)
		swatch_b_when_stack_has_two_unsorted_element(b);
	if (arr_is_desending(n, b))
		while (n-- > 0)
		{
			a->tab[++a->top] = b->tab[b->top--];
			ft_putstr_w_new_line("pa");
		}
}

void	manage_a(int n, t_stack *a,  t_stack *b)
{
	if (n == 2)
		swatch_when_stack_has_two_unsorted_element(a);
	if (arr_is_sorted(n, a) && n != a->top + 1)
	{
		while (n-- > 0)
		{
			b->tab[++b->top] = a->tab[a->top--];
			ft_putstr_w_new_line("pb");
		}
	}
}

void    send_ele_from_b_to_a(int nb_to_move, int mid, t_stack *b, t_stack *a)
{
	int	t;

	t = 0;
	while (nb_to_move)
	{
		while (nb_to_move && b->tab[b->top] > mid)
		{
			a->tab[++(a->top)] = b->tab[b->top--];
			ft_putstr_w_new_line("pa");
			nb_to_move--;
		}
		while (nb_to_move && b->tab[b->top] <= mid)
		{
			rotate_stack(b);
			ft_putstr_w_new_line("rb");
			t++;
		}
	}
	while (t)
	{
		reverse_stack(b);
		ft_putstr_w_new_line("rrb");
		t--;
	}

}
