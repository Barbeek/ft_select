/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:54:59 by pespalie          #+#    #+#             */
/*   Updated: 2018/05/09 11:55:04 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_color(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(RESET);
	ft_putstr("  ");
}
