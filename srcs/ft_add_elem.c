/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:41:52 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/04 17:26:09 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

t_djik	*ft_add_static_value(t_djik *elem)
{
	elem->status = 0;
	elem->ants_in_path = 0;
	elem->special = 0;
	elem->input = 1;
	elem->output = 0;
	elem->end_path = 0;
	elem->bfs_end = -1;
	return (elem);
}

int		ft_add_elem(t_djik **djik, char *name, int end)
{
	t_djik *elem;
	t_djik *tmp;

	if (!(elem = (t_djik *)malloc(sizeof(t_djik))))
		return (-1);
	tmp = (*djik);
	while (tmp->next != NULL)
		tmp = tmp->next;
	elem->name = name;
	elem = ft_add_static_value(elem);
	if (end == 1)
		elem->special = 2;
	if (!(elem->from = (t_djik **)malloc(sizeof(t_djik *) * 2)))
		return (-1);
	elem->from[0] = (*djik);
	elem->from[1] = NULL;
	if (!(elem->link = (t_djik **)malloc(sizeof(t_djik *) * 1)))
		return (-1);
	elem->link[0] = NULL;
	elem->next = NULL;
	elem->distance = (*djik)->distance + 1;
	ft_add_link(*djik, elem);
	tmp->next = elem;
	return (0);
}
