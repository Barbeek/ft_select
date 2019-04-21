/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:51:54 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/23 10:03:25 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (((unsigned char *)str1)[i] == ((unsigned char *)str2)[j])
	{
		if (((unsigned char *)str1)[i] == '\0')
			return (0);
		i++;
		j++;
	}
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[j]);
}
