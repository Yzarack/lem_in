/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:40:14 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/13 18:42:22 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_valid_nb(char **split, char *s)
{
	int	cpt;

	cpt = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[cpt])
		{
			if (!ft_isdigit(s[cpt]))
				ft_free_str_error(split, 1);
			cpt++;
		}
	}
	else
		ft_free_str_error(split, 1);
}

void	ft_is_valid(char *line)
{
	char	**split;

	if (line != NULL && line[0] != 0 &&
	line[0] == '#' && line[1] == '#')
	{
		free(line);
		return ;
	}
	split = ft_strsplit(line, ' ');
	if (split[0][0] == 'L' || split[1] == NULL ||
	split[2] == NULL || split[3] != NULL || line[0] == ' ')
	{
		free(line);
		ft_free_str_error(split, 1);
	}
	free(line);
	ft_valid_nb(split, split[1]);
	ft_valid_nb(split, split[2]);
	ft_free_str_error(split, 0);
}

void	ft_get_rooms_disp(t_map *map, char *line)
{
	char *tmp;

	if (map->room_list_disp == NULL)
		map->room_list_disp = ft_strjoin(line, "\n");
	else
	{
		tmp = map->room_list_disp;
		map->room_list_disp = ft_strjoinendl(tmp, line);
		free(tmp);
	}
}

void	ft_rooms(t_map *map, char *line)
{
	char *tmp;

	ft_get_rooms_disp(map, line);
	tmp = ft_strdup(line);
	map->step = 2;
	if ((line != NULL && line[0] != '#') || (line != NULL &&
	line[0] != 0 && line[0] == '#' && line[1] == '#'))
		map->room_list = ft_join_str(map->room_list, tmp, 1);
	if (line[0] == '#' && line[1] != '#')
	{
		free(tmp);
		free(line);
		return ;
	}
	ft_is_valid(line);
	map->nb_rooms++;
}
