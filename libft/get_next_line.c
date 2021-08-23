/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:10:21 by xinwang           #+#    #+#             */
/*   Updated: 2021/08/21 20:33:32 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_new_str(char **str, char **buff, int nb_read)
{
	char	*s;

	s = ft_strnew(ft_strlen(*str) + nb_read + 1);
	if (!s)
		return (-1);
	if (*str)
	{
		s = ft_strncat(s, *str, ft_strlen(*str));
		free(*str);
	}
	*str = ft_strncat(s, *buff, nb_read);
	free(*buff);
	return (1);
}

static int	get_content_from_file(int fd, char **str)
{
	int		nb_read;
	char	*buff;
	int		v;

	buff = ft_strnew(BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	nb_read = read(fd, buff, BUFFER_SIZE);
	if (nb_read <= 0)
	{
		free(buff);
		return (nb_read);
	}
	buff[nb_read] = '\0';
	v = get_new_str(str, &buff, nb_read);
	if (v == -1)
		return (-1);
	if (no_newline_in_str(*str))
		return (get_content_from_file(fd, str));
	return (1);
}

static int	extract_line(char **line, char **str, int *i, int *j)
{
	char	*s;
	char	*s1;
	char	*tmp;

	while ((*str)[*i] && (*str)[*i] != '\n')
		(*i)++;
	s = ft_strnew(*i + 1);
	if (!s)
		return (-1);
	*line = ft_strncat(s, *str, *i);
	*j = ft_strlen(*str) - *i;
	if (!*j)
		return (nigun_static(str, 0));
	s1 = ft_strnew(*j);
	if (s1)
	{
		tmp = ft_strncat(s1, *str + *i + 1, *j - 1);
		free(*str);
		*str = tmp;
		return (1);
	}
	return (nigun_static(str, -1));
}

static int	manage_str(char **str, char **line)
{
	int	res;
	int	i;
	int	j;

	i = 0;
	j = 0;
	res = 0;
	res = extract_line(line, str, &i, &j);
	if (res != 1)
	{
		if (res == -1)
			return (nigun_static(str, -1));
		return (nigun_static(str, 0));
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (no_newline_in_str(str))
	{
		if (get_content_from_file(fd, &str) == -1)
			return (nigun_static(&str, -1));
		if (!str)
		{
			*line = ft_strnew(1);
			return (0);
		}
	}
	return (manage_str(&str, line));
}
