/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_old_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:04:07 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/06 23:41:59 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

/*
** Recupere le prev avant ca modification si le chemin trouve n'utilise pas de
** B path ou C path
*/

void	li_get_old_prev(t_board board, int **matrice)
{
	t_room *rooms;
	t_room *checkpoint;
	int i;

	i = -1;
	rooms = &board.rooms[1];
	checkpoint = rooms;
	while (++i < board.links_count)
	{
		if (matrice[i][room.link[i]] == 4 ||
	}
}