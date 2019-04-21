/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:11:03 by pespalie          #+#    #+#             */
/*   Updated: 2018/08/09 21:22:42 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		make_line(int fd, char **str)
{
	char	*buff;
	char	*tmp;
	int		j;

	if (!(buff = ft_strnew(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	j = read(fd, buff, BUFF_SIZE);
	if (j > 0)
	{
		buff[j] = '\0';
		tmp = ft_strjoin(*str, buff);
		if (!tmp)
			return (-1);
		free(*str);
		*str = tmp;
	}
	free(buff);
	return (j);
}

int		ft_malloc_str(char **line, char **end_str, char **str)
{
	*line = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(*end_str));
	*end_str = ft_strdup(*end_str + 1);
	free(*str);
	*str = *end_str;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*end_str;
	int			i;

	if ((!str && (str = ft_strnew(sizeof(*str))) == NULL) || !line)
		return (-1);
	while (!(end_str = ft_strchr(str, '\n')))
	{
		if ((i = make_line(fd, &str)) == 0)
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "\n");
		}
		if (i < 0)
			return (-1);
		else
			end_str = ft_strchr(str, '\n');
	}
	return (ft_malloc_str(line, &end_str, &str));
}
