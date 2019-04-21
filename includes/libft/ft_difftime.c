/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_difftime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:07:36 by pespalie          #+#    #+#             */
/*   Updated: 2018/05/09 13:04:27 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>
#include <stdio.h>

double	ft_difftime(struct stat *time_end, struct stat *time_beg)
{
	double difftime;

	difftime = (time_end->st_mtime) - (time_beg->st_mtime);
	return (difftime);
}
