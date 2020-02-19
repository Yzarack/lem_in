/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_karp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:39:54 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/14 03:34:15 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_remove_line(t_map *map, int count)
{
	free(map->tunnels_split[count]);
	while (map->tunnels_split[count])
	{
		map->tunnels_split[count] = map->tunnels_split[count + 1];
		count++;
	}
}

void	ft_bfs(t_djik *djik, t_map *map)
{
	char *buff;

	while (djik != NULL)
	{
		if (ft_strcmp(djik->name, map->end) != 0)
		{
			while ((buff = ft_find_link(map, djik->name, djik, -1)) != NULL)
			{
				if (ft_strcmp(buff, map->end) == 0)
					ft_add_elem(&djik, buff, 1);
				else
					ft_add_elem(&djik, buff, 0);
				djik->output++;
			}
		}
		djik = djik->next;
	}
}

void	ft_print_map(t_map *map)
{
	ft_putnbr(map->nb_ants);
	ft_putchar('\n');
	ft_putendl(map->room_list_disp);
	ft_putendl(map->tunnels_disp);
}

int		ft_resolve_karp(t_map *map)
{
	t_djik	*djik;
	t_djik	*save;

	map->end = ft_find_end(map->room_list);
	djik = ft_init_start(map);
	map->start = djik->name;
	save = djik;
	ft_bfs(djik, map);
	while (djik && djik->special != 2)
		djik = djik->next;
	if (djik == NULL)
	{
		ft_finish_djik(save, map);
		return (-1);
	}
	djik = save;
	ft_delete_room(djik);
	ft_endbfs(djik);
	ft_count_end(djik);
	ft_print_map(map);
	ft_print(djik, map->nb_ants);
	ft_finish_djik(djik, map);
	return (1);
}
