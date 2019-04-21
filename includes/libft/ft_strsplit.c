/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 01:42:26 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/30 14:30:45 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (s[0] != '\0')
		count++;
	return (count);
}

static char		*ft_fill(char const *s, char c, int *i)
{
	char	*str;
	int		k;

	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s)))))
		return (NULL);
	k = 0;
	while (s[*i] != c && s[*i])
	{
		str[k] = s[*i];
		k++;
		*i = *i + 1;
	}
	str[k] = '\0';
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;
	int		mot;

	i = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	mot = ft_count(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (mot + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (k < mot && s[i])
	{
		tab[k] = ft_fill(s, c, &i);
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
