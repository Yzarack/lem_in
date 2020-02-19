/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:52:24 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/14 11:34:41 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_count_backtrack(t_djik *djik, t_djik *tmp)
{
	int result;
	int i;

	result = 0;
	i = -1;
	if (djik->special == 2)
		return (1);
	if (djik->special == 1)
		return (0);
	if (djik->status == 1)
		return (0);
	djik->status = 1;
	while (++i < djik->output)
		if (djik->link[i] != tmp)
			result += ft_count_backtrack(djik->link[i], djik);
	i = 0;
	while ((i < djik->input && djik->output == 0)
			|| (djik->output == 1 && djik->link[0] == tmp && i < djik->input))
	{
		if (djik->from[i] != tmp)
			result += ft_count_backtrack(djik->from[i], djik);
		i++;
	}
	djik->end_path += result;
	return (result);
}

void	ft_insertion_sort_link(t_djik *djik)
{
	t_djik	*buff;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < djik->output)
	{
		j = i;
		while (++j < djik->output)
		{
			if ((djik->link[j]->end_path < djik->link[i]->end_path &&
						djik->link[i]->bfs_end != 1) ||
					(djik->link[j]->end_path == djik->link[i]->end_path &&
					djik->link[j]->bfs_end < djik->link[i]->bfs_end) ||
					(djik->link[j]->bfs_end == 1 && djik->link[i]->bfs_end > 1))
			{
				buff = djik->link[i];
				djik->link[i] = djik->link[j];
				djik->link[j] = buff;
				j = i;
			}
		}
	}
}

void	ft_short_path(t_djik *djik)
{
	int		i;
	int		tmp;
	t_djik	*save;

	i = -1;
	save = djik;
	while (++i < save->output)
	{
		djik = save->link[i];
		tmp = 0;
		while (djik->special != 2 && tmp == 0)
		{
			if (djik->distance == 1)
				save->link[i] = djik;
			if (djik->output > 0)
				djik = djik->link[0];
			else if (djik->special == 0)
			{
				ft_delete_link(save, save->link[i]);
				tmp = 1;
				i--;
			}
		}
		djik = save;
	}
}

void	ft_inner_count_end(t_djik *djik)
{
	int i;

	i = -1;
	while (++i < djik->output)
	{
		if (ft_find_path(djik->link[i], djik, 0) == -1)
		{
			ft_delete_from(djik->link[i], djik);
			ft_delete_link(djik, djik->link[i]);
		}
		else
			ft_delete_path(djik->link[i]);
		ft_reset(djik);
		ft_delete_room(djik);
	}
	i = -1;
	while (++i < djik->output)
	{
		if (djik->link[i]->status == 0 && djik->link[i]->special == 0)
		{
			ft_delete_link(djik, djik->link[i]);
			i = -1;
		}
	}
}

void	ft_count_end(t_djik *djik)
{
	int		i;

	i = -1;
	while (++i < djik->output)
	{
		ft_count_backtrack(djik->link[i], djik);
		ft_reset(djik);
	}
	i = -1;
	while (++i < djik->output)
	{
		if (djik->link[i]->end_path == 0 &&
		djik->link[i]->special == 0)
		{
			ft_delete_link(djik, djik->link[i]);
			i = -1;
		}
	}
	ft_insertion_sort_link(djik);
	ft_inner_count_end(djik);
	ft_short_path(djik);
}
