/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:11:50 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/23 15:32:51 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s2;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = (ft_strlen(s) - 1);
	s2 = ft_strnew(len + 1);
	if (!s2)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	while (i <= len)
	{
		s2[j] = s[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
