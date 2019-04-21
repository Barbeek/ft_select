/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:03:30 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/30 14:26:31 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	if ((str = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
