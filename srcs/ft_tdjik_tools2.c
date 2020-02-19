/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdjik_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:41:39 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/13 14:29:15 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

#include <stdio.h>

void	ft_delete_room_next(t_djik *djik, t_djik *save)
{
	t_djik	**from;
	int		input;

	input = djik->input;
	if (djik->output <= 0)
	{
		save->next = djik->next;
		from = djik->from;
		while (input > 0)
		{
			ft_delete_link(from[input - 1], djik);
			input--;
		}
		free(djik->name);
		free(djik->link);
		free(djik);
		djik = NULL;
	}
	else
		return ;
	free(from);
}

void	ft_delete_room_next_output(t_djik *djik, t_djik *save)
{
	t_djik	**link;
	int		output;

	output = djik->output;
	if (djik->input <= 0)
	{
		save->next = djik->next;
		link = djik->link;
		while (output > 0)
		{
			ft_delete_from(link[output - 1], djik);
			output--;
		}
		free(djik->name);
		free(djik->from);
		free(djik);
		djik = NULL;
	}
	else
		return ;
	free(link);
}

int		ft_delete_no_input(t_djik *djik)
{
	int i;

	i = -1;
	while (++i < djik->input)
	{
		if (!(djik->from[i]->output == 1 && djik->from[i]->input == 1))
			return (0);
	}
	return (1);
}

void	ft_delete_room(t_djik *djik)
{
	t_djik *begin;
	t_djik *save;

	begin = djik;
	save = djik;
	while (djik)
	{
		if (djik->output == 0 && djik->input == 1 && djik->special == 0)
		{
			ft_delete_room_next(djik, save);
			djik = begin;
		}
		if (djik->input == 0 && djik->output == 1 && djik->special == 0)
		{
			ft_delete_room_next_output(djik, save);
			djik = begin;
		}
		save = djik;
		djik = djik->next;
	}
}

t_djik	**ft_djikdup(t_djik **djik)
{
	int		i;
	t_djik	**dup;

	i = 0;
	while (djik[i])
		i++;
	if (!(dup = (t_djik**)malloc(sizeof(t_djik) * (i + 1))))
		return (NULL);
	i = -1;
	while (djik[++i])
		dup[i] = djik[i];
	dup[i] = NULL;
	free(djik);
	return (dup);
}
