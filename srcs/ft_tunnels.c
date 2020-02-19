/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tunnels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:40:46 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/13 22:23:24 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_get_tunnels_disp(t_map *map, char *line)
{
	char	*buff;

	if (map->tunnels_disp == NULL)
		map->tunnels_disp = ft_strjoin(line, "\n");
	else
	{
		buff = map->tunnels_disp;
		map->tunnels_disp = ft_strjoinendl(buff, line);
		free(buff);
	}
}

void	ft_exit_tunnels(t_map *map, int count, char *line)
{
	if (count != 1)
	{
		free(line);
		ft_exit_lem_in(map, 1);
	}
}

void	ft_tunnels(t_map *map, char *line)
{
	int count;
	int	i;

	i = -1;
	ft_get_tunnels_disp(map, line);
	count = 0;
	map->step == 2 ? map->step = 3 : 0;
	if (map->step != 3)
	{
		free(line);
		ft_exit_lem_in(map, 1);
	}
	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
			ft_exit_lem_in(map, 1);
		free(line);
		return ;
	}
	while (line[++i])
		if (line[i] == '-')
			count++;
	ft_exit_tunnels(map, count, line);
	map->tunnels = ft_join_str(map->tunnels, line, 1);
}
