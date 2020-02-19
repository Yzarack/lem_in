/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:39:42 by jthierce          #+#    #+#             */
/*   Updated: 2019/12/20 17:42:05 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int		ft_init_map(t_map **map)
{
	if (!((*map) = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	(*map)->start = NULL;
	(*map)->room_list = NULL;
	(*map)->room_list_disp = NULL;
	(*map)->rooms_names = NULL;
	(*map)->tunnels = NULL;
	(*map)->tunnels_disp = NULL;
	(*map)->nb_rooms = 0;
	(*map)->nb_ants = 0;
	(*map)->step = 0;
	(*map)->check[0] = 0;
	(*map)->check[1] = 0;
	(*map)->tunnels_split = NULL;
	return (0);
}

t_map	*ft_init_map_2(t_map *map)
{
	int i;

	i = -1;
	if ((map->rooms_names = (char **)ft_memalloc(sizeof(char *) *
	(map->nb_rooms + 1))) == NULL)
		return (NULL);
	if ((map->tunnels_split = ft_strsplit(map->tunnels, '\n')) == NULL)
		return (NULL);
	while (++i < map->nb_rooms)
		map->rooms_names[i] = NULL;
	map->rooms_names[i] = NULL;
	return (map);
}

int		ft_is_str_empty(char *s)
{
	size_t cpt;

	cpt = 0;
	while (s[cpt] && s[cpt] == ' ')
		cpt++;
	if (cpt == ft_strlen(s))
		return (1);
	return (0);
}

int		ft_found(char **split, char *needle)
{
	if (split != NULL && (ft_strcmp(split[0], needle) == 0 ||
				ft_strcmp(split[1], needle) == 0))
	{
		ft_free_str_error(split, 0);
		return (1);
	}
	return (0);
}

char	*ft_strstr_custom(const char *haystack, char *needle)
{
	int		i;
	int		j;
	int		needle_size;
	char	**split;

	needle_size = ft_strlen(needle);
	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] && haystack[i + j])
		{
			if (j == needle_size - 1)
			{
				split = ft_strsplit(haystack, '-');
				if (ft_found(split, needle) == 1)
					return ((char *)haystack + i);
				ft_free_str_error(split, 0);
			}
			j++;
		}
	}
	return (0);
}
