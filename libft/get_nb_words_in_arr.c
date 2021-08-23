/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:27:03 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/13 17:47:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_nb_words_in_arr(char *str, char c)
{
	int			i;
	int			nb_words;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		if ((!i && (str[i] != c))
			|| (i > 0 && (str[i - 1] == c) && (str[i] != c)))
			nb_words++;
		i++;
	}
	return (nb_words);
}
