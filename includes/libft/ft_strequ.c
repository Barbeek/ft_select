/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:04:42 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/23 17:40:12 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] == s2[j])
	{
		if (s1[i] == '\0' && s2[j] == '\0')
			return (1);
		i++;
		j++;
	}
	return (0);
}
