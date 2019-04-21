/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:23:00 by pespalie          #+#    #+#             */
/*   Updated: 2017/11/30 14:25:16 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*liste;
	t_list	*suivant;

	liste = *alst;
	while (liste)
	{
		suivant = liste->next;
		(del)((liste)->content, (liste)->content_size);
		free(liste);
		liste = suivant;
	}
	*alst = NULL;
}
