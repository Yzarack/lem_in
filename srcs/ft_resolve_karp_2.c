/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_karp_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:38:53 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/14 03:37:02 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_delete_link(t_djik *djik, t_djik *del)
{
	t_djik	**buff;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(buff = (t_djik **)malloc(sizeof(t_djik *) * djik->output)))
		return ;
	while (++i < djik->output)
	{
		if (del == djik->link[i])
			i++;
		if (i < djik->output)
		{
			buff[j] = djik->link[i];
			j++;
		}
	}
	buff[j] = NULL;
	free(djik->link);
	djik->link = buff;
	djik->output--;
}

void	ft_delete_from(t_djik *djik, t_djik *del)
{
	t_djik	**buff;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(buff = (t_djik **)malloc(sizeof(t_djik *) * (djik->input))))
		return ;
	while (++i < djik->input)
	{
		if (del == djik->from[i])
			i++;
		if (i < djik->input)
		{
			buff[j] = djik->from[i];
			j++;
		}
	}
	buff[j] = NULL;
	free(djik->from);
	djik->from = buff;
	djik->input--;
}

int		ft_is_good_input(t_djik *djik)
{
	while (djik->special != 1)
	{
		if (djik->output > 1)
			return (0);
		djik = djik->from[0];
	}
	return (1);
}
