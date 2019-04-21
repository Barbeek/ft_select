/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:22:03 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/23 11:01:55 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*src;
	int		i;
	int		nbr;
	int		negative;

	src = (char *)str;
	i = 0;
	negative = 0;
	nbr = 0;
	while (src[i] == ' ' || src[i] == '\n' || src[i] == '\t' ||
			src[i] == '\v' || src[i] == '\r' || src[i] == '\f')
		i++;
	if (src[i] == '-')
		negative = 1;
	if (src[i] == '-' || src[i] == '+')
		i++;
	while (src[i] >= '0' && src[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (src[i] - 48);
		i++;
	}
	if (negative == 1)
		return (nbr * -1);
	return (nbr);
}
