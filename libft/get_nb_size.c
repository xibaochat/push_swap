/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:38:01 by user42            #+#    #+#             */
/*   Updated: 2020/12/13 17:38:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_nb_size(int n)
{
	int				size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n > 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}
