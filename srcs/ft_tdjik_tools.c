/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdjik_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:09:57 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/13 21:45:59 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char	*ft_find_start(char *room_names)
{
	char	**s;
	char	**s2;
	char	*ret;
	int		i;

	i = -1;
	s = ft_strsplit(room_names, '\n');
	while (s[++i])
	{
		if (ft_strcmp(s[i], "##start") == 0)
		{
			i++;
			while (s[i][0] == '#')
				i++;
			s2 = ft_strsplit(s[i], ' ');
			ft_free_str_error(s, 0);
			ret = ft_strdup(s2[0]);
			ft_free_str_error(s2, 0);
			return (ret);
		}
	}
	ft_free_str_error(s, 0);
	return (NULL);
}

char	*ft_find_end(char *room_names)
{
	char	**s1;
	char	**s2;
	char	*dup;
	int		i;

	i = -1;
	s1 = ft_strsplit(room_names, '\n');
	while (s1[++i])
	{
		if (ft_strcmp(s1[i], "##end") == 0)
		{
			i++;
			while (s1[i][0] == '#')
				i++;
			s2 = ft_strsplit(s1[i], ' ');
			ft_free_str_error(s1, 0);
			dup = ft_strdup(s2[0]);
			ft_free_str_error(s2, 0);
			return (dup);
		}
	}
	ft_free_str_error(s1, 0);
	return (NULL);
}

int		ft_add_link(t_djik *djik, t_djik *link)
{
	int		i;

	i = -1;
	while (++i < djik->output)
		if (djik->link[i] == link)
			return (-1);
	i = 0;
	djik->link = ft_djikdup(djik->link);
	while (djik->link[i])
		i++;
	djik->link[i] = link;
	djik->link[i + 1] = NULL;
	return (0);
}

int		ft_is_in_path(t_djik *djik, char *name)
{
	t_djik *tmp;

	tmp = djik;
	while (tmp->from != NULL)
		tmp = tmp->from[0];
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_djik	*ft_init_start(t_map *map)
{
	t_djik *tmp;

	if (!(tmp = (t_djik *)malloc(sizeof(t_djik))))
		return (NULL);
	tmp->name = ft_find_start(map->room_list);
	tmp->special = 1;
	tmp->distance = 0;
	tmp->ants_in_path = 0;
	tmp->end_path = 0;
	tmp->input = 0;
	tmp->output = 0;
	tmp->bfs_end = -1;
	tmp->status = 0;
	tmp->next = NULL;
	if (!(tmp->link = (t_djik **)malloc(sizeof(t_djik *) * 2)))
		return (NULL);
	tmp->link[0] = NULL;
	tmp->link[1] = NULL;
	tmp->from = NULL;
	return (tmp);
}
