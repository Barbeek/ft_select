/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:54:47 by pespalie          #+#    #+#             */
/*   Updated: 2018/05/09 11:54:50 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_back(char *str, char *back, char *color)
{
	ft_putstr(back);
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(RESET);
	ft_putstr("  ");
}
