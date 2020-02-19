/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:35:33 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/14 03:31:21 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int		ft_add_from(t_djik *djik, t_djik *from)
{
	int		i;

	i = -1;
	while (++i < djik->input)
		if (djik->from[i] == from)
			return (-1);
	i = 0;
	djik->from = ft_djikdup(djik->from);
	while (djik->from[i])
		i++;
	djik->from[i] = from;
	djik->from[i + 1] = NULL;
	return (0);
}

int		ft_add_from_link(t_djik *djik, char *name)
{
	t_djik *tmp;

	tmp = djik;
	while (tmp->special != 1)
		tmp = tmp->from[0];
	while (ft_strcmp(tmp->name, name) != 0)
		tmp = tmp->next;
	if (djik->distance > tmp->distance && tmp->special != 2)
		return (0);
	if (ft_add_link(djik, tmp) == -1)
		return (-1);
	djik->output++;
	ft_add_from(tmp, djik);
	tmp->input++;
	return (0);
}

char	*ft_return_link(t_map *map, int i, int j, char **t2)
{
	char *buff;

	ft_remove_line(map, i);
	buff = ft_strdup(t2[j]);
	ft_free_str_error(t2, 0);
	return (buff);
}

char	*ft_find_link(t_map *map, char *name, t_djik *djik, int i)
{
	char	**t2;
	int		j;

	while (map->tunnels_split[++i])
	{
		if (ft_strstr_custom(map->tunnels_split[i], name) != NULL)
		{
			j = -1;
			t2 = ft_strsplit(map->tunnels_split[i], '-');
			while (t2[++j])
			{
				if (ft_strcmp(t2[j], name) != 0 && !ft_is_in_path(djik, t2[j]))
					return (ft_return_link(map, i, j, t2));
				else if (ft_strcmp(t2[j], name) != 0)
				{
					ft_remove_line(map, i);
					ft_add_from_link(djik, t2[j]);
					i--;
				}
			}
			ft_free_str_error(t2, 0);
		}
	}
	return (NULL);
}
