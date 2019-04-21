/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:57:00 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/22 15:57:22 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (((char *)needle)[0] == 0)
		return (((char *)haystack));
	while (((char *)haystack)[i] != '\0')
	{
		j = 0;
		while (((char *)needle)[j] == ((char *)haystack)[i + j])
		{
			if (((char *)needle)[j + 1] == '\0')
				return (((char *)haystack) + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
