/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_empty_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:49:26 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/21 00:54:26 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_empty_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strlen(av[i])
			|| (ft_strlen(av[i]) == 1 && (av[i][0] == '-' || av[i][0] == '+')))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}
