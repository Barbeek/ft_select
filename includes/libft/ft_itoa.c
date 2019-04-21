/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 05:09:40 by pespalie          #+#    #+#             */
/*   Updated: 2018/05/17 22:11:41 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int n)
{
	int		count;

	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = ft_intlen(n);
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	s[len] = '\0';
	while (n)
	{
		s[len - 1] = (n % 10) + '0';
		len--;
		n = n / 10;
	}
	return (s);
}
