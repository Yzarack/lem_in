/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:37:38 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/13 22:11:20 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char	*ft_join_str(char *s1, char *s2, int clean)
{
	char	*dest;
	char	*buff;

	if (s1 == NULL || s1[0] == 0)
		return (s2);
	dest = ft_strjoin("\n", s2);
	buff = ft_strjoin(s1, dest);
	free(dest);
	free(s1);
	if (clean == 1)
		free(s2);
	return (buff);
}

void	ft_free_str_error(char **str, int error)
{
	int cpt;

	cpt = 0;
	if (str == NULL)
		return ;
	while (str[cpt])
		str[cpt] ? free(str[cpt++]) : 0;
	free(str);
	str = NULL;
	if (error == 1)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
}

void	ft_exit_lem_in(t_map *m, int error)
{
	free(m->room_list);
	if (m->tunnels_split != NULL)
		ft_free_str_error(m->tunnels_split, 0);
	ft_free_str_error(m->rooms_names, 0);
	if (m->room_list_disp != NULL)
		free(m->room_list_disp);
	if (m->tunnels_disp != NULL)
		free(m->tunnels_disp);
	free(m->tunnels);
	free(m);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}

void	ft_check_tunnel(char *tunnel)
{
	char	**t;

	t = ft_strsplit(tunnel, '-');
	if (t[2] != NULL)
		ft_free_str_error(t, 1);
	ft_free_str_error(t, 0);
}

void	ft_get_nb_ants(t_map *map, char *line)
{
	int		cpt;

	cpt = 0;
	map->step = 1;
	if ((line[0] == '#' && line[1] != '#') || (line[0] == '#'
	&& line[1] == '#' && ft_strcmp(line, "##start") != 0 &&
	ft_strcmp(line, "##end") != 0))
	{
		free(line);
		return ;
	}
	while (ft_isdigit(line[cpt]) || line[cpt] == '+')
		cpt++;
	if (line[cpt] != 0)
	{
		free(line);
		ft_exit_lem_in(map, 1);
	}
	if ((map->nb_ants = ft_atoi(line)) <= 0 || ft_strlen(line) > 10)
	{
		free(line);
		ft_exit_lem_in(map, 1);
	}
	free(line);
}
