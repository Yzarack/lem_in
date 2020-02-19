/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms_tunnels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:00:41 by jthierce          #+#    #+#             */
/*   Updated: 2019/11/30 13:20:23 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_extension_rooms_tunnels(t_map *map, char **s, int i)
{
	int		j;
	char	**buff;

	j = 0;
	buff = ft_strsplit(s[i], '-');
	while (map->rooms_names[j] &&
	ft_strcmp(buff[0], map->rooms_names[j]) != 0)
		j++;
	if (!map->rooms_names[j] ||
	ft_strcmp(buff[0], map->rooms_names[j]) != 0)
		ft_exit_lem_in(map, 1);
	j = 0;
	while (map->rooms_names[j] &&
	ft_strcmp(buff[1], map->rooms_names[j]) != 0)
		j++;
	if (!map->rooms_names[j] ||
	ft_strcmp(buff[1], map->rooms_names[j]) != 0)
		ft_exit_lem_in(map, 1);
	ft_free_str_error(buff, 0);
}

int		ft_rooms_tunnels(t_map *map)
{
	int		i;
	char	**s;

	i = -1;
	s = ft_strsplit(map->tunnels, '\n');
	while (s[++i])
	{
		ft_extension_rooms_tunnels(map, s, i);
		free(s[i]);
	}
	free(s);
	return (0);
}
