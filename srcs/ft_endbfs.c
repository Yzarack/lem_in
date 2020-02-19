/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endbfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:46:42 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/06 12:56:02 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int		save_min_result(t_djik *djik)
{
	int save_min;
	int	i;

	save_min = INT_MAX;
	i = -1;
	while (++i < djik->input)
	{
		if (djik->from[i]->bfs_end != -1 && djik->from[i]->bfs_end < save_min)
			save_min = djik->from[i]->bfs_end;
	}
	i = -1;
	while (++i < djik->output)
	{
		if (djik->link[i]->bfs_end != -1 && djik->link[i]->bfs_end < save_min)
			save_min = djik->link[i]->bfs_end;
	}
	return (save_min);
}

void	ft_endbfs_backtrack(t_djik *djik)
{
	int i;
	int save_min;

	i = -1;
	if (djik == NULL)
		return ;
	if (djik->special == 2)
	{
		while (++i < djik->input)
			djik->from[i]->bfs_end = 1;
		djik->bfs_end = 0;
	}
	ft_endbfs_backtrack(djik->next);
	if (djik->special == 2 || djik->bfs_end != -1)
		return ;
	save_min = save_min_result(djik);
	if (save_min != INT_MAX)
		djik->bfs_end = save_min + 1;
}

void	ft_endbfs(t_djik *save)
{
	t_djik	*djik;

	djik = save;
	while (djik != NULL)
	{
		if (djik->bfs_end == -1 && djik->special != 2)
		{
			djik = save;
			ft_endbfs_backtrack(djik);
		}
		else
			djik = djik->next;
	}
}
