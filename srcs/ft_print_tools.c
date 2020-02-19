/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:07:58 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/04 15:44:44 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int		ft_get_path_len(t_djik *djik)
{
	int len;

	len = 0;
	while (djik && djik->link[0])
	{
		djik = djik->link[0];
		len++;
	}
	if (djik->special == 2)
	{
		if (len > 0)
			return (len);
		else
			return (1);
	}
	return (-1);
}

t_djik	**ft_sort_path(t_djik **djik, int *paths_lenght, int nb_path)
{
	int		tmp;
	t_djik	*tmp2;
	int		cpt;

	cpt = 0;
	while (cpt < nb_path - 1)
	{
		if (paths_lenght[cpt] > paths_lenght[cpt + 1])
		{
			tmp = paths_lenght[cpt];
			paths_lenght[cpt] = paths_lenght[cpt + 1];
			paths_lenght[cpt + 1] = tmp;
			tmp2 = djik[cpt];
			djik[cpt] = djik[cpt + 1];
			djik[cpt + 1] = tmp2;
			cpt = -1;
		}
		cpt++;
	}
	return (djik);
}

int		ft_send_to_path(int *paths_lenght, int current_path, int nb_ants)
{
	int	ret;
	int	cpt;

	cpt = 0;
	ret = 0;
	if (current_path == 0)
		return (1);
	while (cpt < current_path)
	{
		ret += paths_lenght[current_path] - paths_lenght[cpt];
		cpt++;
	}
	if (nb_ants > ret)
		return (1);
	return (0);
}

int		ft_get_nb_paths(t_djik *arg)
{
	int		ret;
	t_djik	*djik;

	djik = arg;
	ret = INT_MAX;
	while (djik)
	{
		if (djik->special == 1 || djik->special == 2)
		{
			if (djik->special == 1 && djik->output < ret)
				ret = djik->output;
			if (djik->special == 2 && djik->input < ret)
				ret = djik->input;
		}
		djik = djik->next;
	}
	return (ret);
}

int		ft_check_ants_in_path(t_ant *ant)
{
	while (ant)
	{
		if (ant->current_room->special != 2)
			return (1);
		ant = ant->next;
	}
	return (0);
}
