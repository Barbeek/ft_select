/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:47:48 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/30 13:41:15 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)str1)[i] == ((unsigned char *)str2)[j] && i <= n)
	{
		if (((unsigned char *)str1)[i] == '\0')
			return (0);
		i++;
		j++;
		if (i == n)
			return (0);
	}
	if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[j])
		return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[j]);
	return (0);
}
