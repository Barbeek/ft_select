/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 05:03:32 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/24 15:02:43 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len_d;
	size_t		len_s;
	char		*dst2;
	char		*src2;

	i = 0;
	dst2 = (char *)dst;
	src2 = (char *)src;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src2);
	if (size == 0)
		return (ft_strlen(src2));
	while (src2[i] && (len_d + i) < (size - 1))
	{
		dst2[len_d + i] = src2[i];
		i++;
	}
	dst2[len_d + i] = '\0';
	if (len_d < size)
		return (len_d + len_s);
	return (len_s + size);
}
