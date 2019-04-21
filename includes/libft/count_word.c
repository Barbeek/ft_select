/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:22:13 by pespalie          #+#    #+#             */
/*   Updated: 2018/08/09 21:22:15 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *line)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			if (line[i + 1] == ' ' || line[i + 1] == '\t'
			|| line[i + 1] == '\n' || line[i + 1] == '\0')
				word++;
		}
		i++;
	}
	return (word);
}
