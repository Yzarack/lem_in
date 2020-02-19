/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:47:58 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/13 17:53:11 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_read_line(t_map *map, char *line)
{
	if (map->nb_ants == 0)
		ft_get_nb_ants(map, line);
	else if (ft_strchr(line, '-') || map->step == 3)
		ft_tunnels(map, line);
	else if ((map->step == 1 || map->step == 2) && !ft_is_str_empty(line))
		ft_rooms(map, line);
	else
	{
		free(line);
		ft_exit_lem_in(map, 1);
	}
}

int		ft_read_map(t_map *map)
{
	char	*line;

	line = NULL;
	while (ft_get_next_line(0, &line) > 0)
		ft_read_line(map, line);
	if (map->step != 3)
		ft_exit_lem_in(map, 1);
	if (map->step == 1 || !map->nb_ants || !map->tunnels[0])
	{
		if (line != NULL)
			free(line);
		ft_exit_lem_in(map, 1);
	}
	if ((map = ft_init_map_2(map)) == NULL)
		return (-1);
	return (0);
}

int		main(void)
{
	t_map *map;

	map = NULL;
	if (ft_init_map(&map) == -1)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	if (ft_read_map(map) == -1)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	ft_check_rooms(map);
	if (!map->check[0] || !map->check[1])
		ft_exit_lem_in(map, 1);
	ft_rooms_tunnels(map);
	if (ft_resolve_karp(map) == -1)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	return (0);
}
