/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:31:46 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/14 13:28:58 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int		*ft_len_tab(t_djik **paths, int nb_path)
{
	int	*paths_lenght;
	int	cpt;

	cpt = 0;
	paths_lenght = (int *)malloc(sizeof(int) * nb_path);
	while (cpt < nb_path)
	{
		paths_lenght[cpt] = ft_get_path_len(paths[cpt]);
		cpt++;
	}
	return (paths_lenght);
}

t_djik	**ft_get_paths(t_djik *djik, int nb_path)
{
	int		cpt;
	int		len;
	t_djik	**paths;

	cpt = 0;
	len = 0;
	paths = (t_djik **)malloc(sizeof(t_djik *) * nb_path);
	while (djik->link[cpt] && djik != NULL)
	{
		len = ft_get_path_len(djik->link[cpt]);
		if (len > 0)
			paths[cpt] = djik->link[cpt];
		else
		{
			paths[cpt] = (t_djik *)malloc(sizeof(NULL));
			paths[cpt] = NULL;
		}
		cpt++;
	}
	return (paths);
}

t_ant	*ft_create_ant(t_djik *current_room, int *index, int *nb_ants)
{
	t_ant *ant;

	if (!(ant = (t_ant *)malloc(sizeof(*ant))))
		return (NULL);
	ant->current_room = current_room;
	ant->index = *index;
	ant->print = 1;
	ant->next = NULL;
	(*index)++;
	(*nb_ants)--;
	return (ant);
}

void	ft_display_and_advance(t_ant *begin)
{
	ft_display_ants(begin);
	ft_advance_ants(begin);
}

int		ft_left_to_print(t_ant *begin)
{
	t_ant *toto;

	toto = begin;
	while (toto)
	{
		if (toto->print == 1)
			return (1);
		toto = toto->next;
	}
	return (0);
}
