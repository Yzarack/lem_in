/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_end_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:59:02 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/14 02:05:01 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	ft_swap_djik(t_djik *djik, t_djik *tmp)
{
	int		i;

	i = -1;
	while (++i < djik->input)
	{
		if (djik->from[i] == tmp)
		{
			djik->from[i] = djik->from[0];
			djik->from[0] = tmp;
		}
	}
}

void	ft_insertion_sort_from(t_djik *djik, t_djik *tmp)
{
	t_djik	*buff;
	int		i;
	int		j;

	j = -1;
	i = 0;
	ft_swap_djik(djik, tmp);
	while (++i < djik->input)
	{
		j = i;
		while (++j < djik->input)
		{
			if (djik->from[j]->end_path < djik->from[i]->end_path)
			{
				buff = djik->from[i];
				djik->from[i] = djik->from[j];
				djik->from[j] = buff;
				j = i;
			}
		}
	}
}

int		ft_find_path_from(t_djik *djik, t_djik *tmp)
{
	int		i;
	int		res;
	t_djik	*buff;

	res = 0;
	i = -1;
	ft_insertion_sort_from(djik, tmp);
	while (i + 1 < djik->input && res != 1)
	{
		i++;
		if (djik->from[i] != tmp)
			res = ft_find_path(djik->from[i], djik, 1);
	}
	if (res == -1)
		return (-1);
	if (djik->input > 1)
	{
		buff = djik->from[i];
		djik->from[i] = djik->from[1];
		djik->from[1] = buff;
	}
	return (1);
}

int		ft_inner_find_path(t_djik *djik, t_djik *tmp)
{
	int		i;
	int		res;
	t_djik	*buff;

	i = -1;
	res = 0;
	ft_insertion_sort_link(djik);
	while (i + 1 < djik->output && res != 1)
	{
		i++;
		if (djik->link[i] != tmp)
			res = ft_find_path(djik->link[i], djik, 0);
	}
	if (res == -1)
		return (-1);
	buff = djik->link[i];
	djik->link[i] = djik->link[0];
	djik->link[0] = buff;
	return (res);
}

int		ft_find_path(t_djik *djik, t_djik *tmp, int rev)
{
	int		i;
	int		res;

	i = -1;
	res = 0;
	if (djik->special == 2)
		return (1);
	if (djik->special != 0 || djik->status != 0)
		return (-1);
	djik->status = 1;
	if ((djik->output > 0 && rev == 0) || (djik->output > 1))
	{
		res = ft_inner_find_path(djik, tmp);
		if (res == -1)
			return (-1);
	}
	else if (djik->input > 1 || rev == 1)
		res = ft_find_path_from(djik, tmp);
	else
		return (-1);
	if (res == 1)
		djik->status = 2;
	return (res);
}
