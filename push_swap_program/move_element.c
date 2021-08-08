#include "push_swap.h"

int		chunk_is_sorted(int n, t_stack *ptr)
{
	int i = ptr->top;
	while (i > ptr->top - n)
	{
		if (ptr->tab[i] > ptr->tab[i - 1])
			return (0);
		--i;
	}
	return (1);
}


int		arr_is_sorted(int n, t_stack *ptr)
{
	--n;
	while (n > 0)
	{
		if (ptr->tab[n] > ptr->tab[n - 1])
			return (0);
		--n;
	}
	return (1);
}

int		arr_is_desending(int n, t_stack *ptr)
{
	int	index;

	index = ptr->top;
	while (n > 1)
	{
		if (ptr->tab[index] < ptr->tab[index - 1])
			return (0);
		--n;
		--index;
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
}

void    send_ele_from_b_to_a(int total_nb, int nb_to_move, int mid, t_stack *b, t_stack *a)
{
	int	t;
	int	lens;
	int	*sorted_tab;

 	t = 0;
	ft_putstr("(O) ------- ");
	ft_putstr_w_new_line(ft_itoa(nb_to_move));
	if (nb_to_move == 3 || nb_to_move == 2)
	{
		ft_putstr_w_new_line("-------- 8====D --------");
		lens = nb_to_move;
		sorted_tab = get_sorted_tab(total_nb, nb_to_move, mid, b);
		while (--lens >= 0)
		{
			while (b->tab[b->top] != sorted_tab[lens])
			{
				rotate_stack(b);
				/* ft_putstr_w_new_line("-------- GO INSIDE  --------"); */
				/* for(int i=0; i < nb_to_move;i++) */
				/* 	ft_putstr_w_new_line(ft_itoa(sorted_tab[i])); */
				/* ft_putstr_w_new_line("--------  GO OUTSIDE --------"); */
				ft_putstr_w_new_line("rb");
				t++;
			}

			if (b->tab[b->top] == sorted_tab[lens])
			{
				ft_putstr_w_new_line("pa");
				a->tab[++(a->top)] = b->tab[b->top--];
			}
			while (t-- > 0)
			{
				reverse_stack(b);
				ft_putstr_w_new_line("rrb");
			}
		}
		free(sorted_tab);
	}
	else
	{
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
				++t;
			}
		}
		while (t > 0)
		{
			reverse_stack(b);
			ft_putstr_w_new_line("rrb");
			--t;
		}
	}
}
