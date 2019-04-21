/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:28:32 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/24 16:00:16 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*meule;
	char	*aiguille;
	size_t	i;
	size_t	j;

	meule = (char *)haystack;
	aiguille = (char *)needle;
	i = 0;
	j = 0;
	if (*aiguille == 0)
		return (&*meule);
	while (i < len && meule[i] != '\0')
	{
		j = 0;
		while (aiguille[j] == meule[i + j] && (i + j) < len)
		{
			j++;
			if (aiguille[j] == '\0')
				return (meule + i);
		}
		i++;
	}
	return (NULL);
}
