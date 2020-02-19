/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:08:12 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/14 01:42:42 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_check_start_end(t_map *map, char **s)
{
	static int i = -1;

	i++;
	if (i > 0)
	{
		map->rooms_names[i] = ft_strdup(s[0]);
		return ;
	}
	map->rooms_names[0] = ft_strdup(s[0]);
}

void	ft_free_start_end(t_map *map, char **line, char **s, int i)
{
	int j;

	j = 0;
	if (ft_strcmp("##start", line[i]) == 0)
		j = 0;
	else
		j = 1;
	if (line[i + 1] == NULL)
		ft_exit_lem_in(map, 1);
	if (++(map->check[j]) > 1 || !ft_strcmp("##start", line[i + 1]) ||
			!ft_strcmp("##end", line[i + 1]) ||
			(line[i + 1][0] == '#' && line[i + 1][1] == '#'))
	{
		ft_free_str_error(s, 0);
		ft_free_str_error(line, 1);
	}
}

int		ft_check_doubles(char *current, char **split)
{
	int	i;
	int	cpt;

	i = 0;
	(void)current;
	cpt = 0;
	while (split[i])
	{
		if (ft_strcmp(current, split[i]) == 0)
			cpt++;
		if (cpt == 2)
			return (-1);
		i++;
	}
	return (1);
}

void	ft_check_rooms(t_map *map)
{
	int		i;
	char	**line;
	char	**s;

	i = 0;
	line = ft_strsplit(map->room_list, '\n');
	while (line[i])
	{
		s = ft_strsplit(line[i], ' ');
		if (ft_strcmp("##start", line[i]) == 0)
			ft_free_start_end(map, line, s, i);
		else if (ft_strcmp("##end", line[i]) == 0)
			ft_free_start_end(map, line, s, i);
		else if (map->check[0] == 1 && line[i][0] != '#')
			ft_check_start_end(map, s);
		else if (map->check[1] == 1 && line[i][0] != '#')
			ft_check_start_end(map, s);
		else if (line[i][0] != '#')
			ft_check_start_end(map, s);
		if (ft_check_doubles(s[0], map->rooms_names) == -1)
			ft_exit_lem_in(map, 1);
		ft_free_str_error(s, 0);
		i++;
	}
	ft_free_str_error(line, 0);
}
