/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:23:03 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/09 23:03:57 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *adr;
	t_list *fin;

	adr = NULL;
	fin = NULL;
	while (lst != NULL)
	{
		if (fin == NULL)
		{
			fin = f(lst);
			adr = fin;
		}
		else
		{
			adr->next = f(lst);
			adr = adr->next;
		}
		lst = lst->next;
	}
	return (fin);
}
