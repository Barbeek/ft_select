/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:08:52 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/12 17:52:54 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	c2;
	int				i;

	dest = ((unsigned char*)s);
	c2 = ((unsigned char)c);
	i = 0;
	while (n--)
	{
		if (dest[i] == c2)
			return (dest + i);
		i++;
	}
	return (NULL);
}
