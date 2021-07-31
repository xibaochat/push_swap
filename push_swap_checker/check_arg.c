#include "push_swap.h"

bool	isNumber(t_stack *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < ptr->lens)
	{
		j = 0;
		if (ptr->arr[i][j] == '-')
			j++;
		while (ptr->arr[i][j])
		{
			if (!ft_isdigit(ptr->arr[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	has_extrem_nb(t_stack *ptr)
{
	int			i;
	long long 	nb;

	i = 0;
	while (i < ptr->lens)
	{
		nb = ft_atoi(ptr->arr[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (true);
		i++;
	}
	return (false);
}

bool	has_duplicates_arg(t_stack *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < ptr->lens)
	{
		j = i + 1;
		while (j < ptr->lens)
		{
			if (!ft_strcmp(ptr->arr[i], ptr->arr[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int		has_invalid_instruction(char *line)
{
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
		&& ft_strcmp(line, "ss") && ft_strcmp(line, "pa")
		&& ft_strcmp(line, "pb") && ft_strcmp(line, "ra")
		&& ft_strcmp(line, "rb") && ft_strcmp(line, "rr")
		&& ft_strcmp(line, "rra") && ft_strcmp(line, "rrb")
		&& ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}
