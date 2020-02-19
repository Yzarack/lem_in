/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_djik.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:35:45 by jthierce          #+#    #+#             */
/*   Updated: 2020/01/31 18:42:58 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_free_ants(t_ant *ants)
{
	t_ant	*buff;

	while (ants)
	{
		buff = ants->next;
		free(ants);
		ants = buff;
	}
}

void	ft_finish_djik(t_djik *djik, t_map *map)
{
	t_djik *buff;

	while (djik != NULL)
	{
		buff = djik->next;
		free(djik->name);
		free(djik->from);
		free(djik->link);
		free(djik);
		djik = buff;
	}
	ft_free_str_error(map->rooms_names, 0);
	ft_free_str_error(map->tunnels_split, 0);
	free(map->room_list);
	free(map->room_list_disp);
	free(map->tunnels_disp);
	free(map->tunnels);
	free(map->end);
	free(map);
}
