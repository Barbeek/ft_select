/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:19:04 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/23 17:40:41 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[j] = s2[i];
		j++;
		i++;
	}
	return (s3);
}
