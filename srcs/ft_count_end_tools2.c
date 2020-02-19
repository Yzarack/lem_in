/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_end_tools2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:16:31 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/14 03:31:13 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	ft_sort_status(t_djik *djik, t_djik *tmp)
{
	t_djik	*buff;
	int		i;
	int		j;

	j = -1;
	i = 0;
	ft_swap_djik(djik, tmp);
	while (++i < djik->input)
	{
		if (djik->from[i]->status == 2)
		{
			buff = djik->from[i];
			djik->from[i] = djik->from[1];
			djik->from[1] = buff;
		}
	}
}

void	ft_toto(t_djik *djik)
{
	if (djik->output == 0)
	{
		djik->output++;
		djik->link[0] = djik->from[1];
		ft_delete_from(djik, djik->from[1]);
		ft_add_from(djik->link[0], djik);
		ft_delete_link(djik->link[0], djik);
		djik->link[0]->input++;
	}
	else
	{
		while (djik->input > 1)
		{
			ft_delete_link(djik->from[1], djik);
			ft_delete_from(djik, djik->from[1]);
		}
	}
}

void	ft_delete_path(t_djik *djik)
{
	int i;

	i = 0;
	if (djik->special == 2)
		return ;
	while (2 < djik->input)
	{
		ft_delete_link(djik->from[2], djik);
		ft_delete_from(djik, djik->from[2]);
	}
	ft_toto(djik);
	while (1 < djik->output)
	{
		ft_delete_from(djik->link[1], djik);
		ft_delete_link(djik, djik->link[1]);
	}
	ft_sort_status(djik->link[0], djik);
	ft_delete_path(djik->link[0]);
}

void	ft_reset(t_djik *djik)
{
	while (djik)
	{
		if (djik->status != 2)
			djik->status = 0;
		djik = djik->next;
	}
}
