/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:28:21 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/14 13:29:01 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_display_ants(t_ant *ant)
{
	t_ant	*begin;
	char	*line;

	line = ft_strnew(0);
	begin = ant;
	while (begin)
	{
		if (begin->print == 1)
		{
			line = ft_strjoinfree(line, "L", 0);
			line = ft_strjoinfree(line, ft_itoa(begin->index), 1);
			line = ft_strjoinfree(line, "-", 0);
			line = ft_strjoinfree(line, begin->current_room->name, 0);
			if (begin->next == NULL || ft_left_to_print(begin->next) == 0)
				line = ft_strjoinfree(line, "\n", 0);
			else
				line = ft_strjoinfree(line, " ", 0);
			if (begin->current_room->special == 2)
				begin->print = 0;
		}
		begin = begin->next;
	}
	ft_putstr(line);
	free(line);
}

void	ft_advance_ants(t_ant *buff)
{
	t_ant *ant;

	ant = buff;
	while (ant)
	{
		if (ant->current_room->special != 2)
			ant->current_room = ant->current_room->link[0];
		ant = ant->next;
	}
}

t_ant	*ft_start_print(int nb_ants, int nb_path, t_djik **paths,
		int *paths_lenght)
{
	int		cpt;
	int		index;
	t_ant	*ant;
	t_ant	*begin;

	index = 1;
	while (nb_ants > 0)
	{
		cpt = -1;
		while (++cpt < nb_path)
		{
			if (index == 1)
			{
				ant = ft_create_ant(paths[0], &index, &nb_ants);
				begin = ant;
			}
			else if (ft_send_to_path(paths_lenght, cpt, nb_ants))
			{
				ant->next = ft_create_ant(paths[cpt], &index, &nb_ants);
				ant = ant->next;
			}
		}
		ft_display_and_advance(begin);
	}
	return (begin);
}

void	ft_end_print(t_ant *begin)
{
	while (ft_check_ants_in_path(begin))
	{
		ft_display_ants(begin);
		ft_advance_ants(begin);
	}
}

void	ft_print(t_djik *djik, int nb_ants)
{
	int		nb_path;
	t_ant	*begin;
	int		*paths_lenght;
	t_djik	**paths;

	nb_path = ft_get_nb_paths(djik);
	paths = ft_get_paths(djik, nb_path);
	paths_lenght = ft_len_tab(paths, nb_path);
	ft_sort_path(paths, paths_lenght, nb_path);
	begin = ft_start_print(nb_ants, nb_path, paths, paths_lenght);
	ft_end_print(begin);
	ft_display_ants(begin);
	ft_free_ants(begin);
	free(paths_lenght);
	free(paths);
}
