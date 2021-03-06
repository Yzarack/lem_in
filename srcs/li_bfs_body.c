/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bfs_body.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:34:38 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/10 05:16:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

static	void li_priority_queu(int *queu, int priority)
{
	int buff;
	int i;

	i = 0; //0 ou -1
	buff = queu[0];
	queu[0] = priority;
	while (queu[++i] != 0)
	{
		priority = queu[i];
		queu[i] = buff;
		buff = priority;
	}
	queu[i] = buff;
}

static	int	li_bfs_type_a(t_board board, int **matrice, int *queu, int j)
{
	int i;

	i = -1;
	while (++i < board.rooms[queu[0]].count_link)
	{
		if (board.rooms[board.rooms[queu[0]].link[i]].status == 0
		|| board.rooms[board.rooms[queu[0]].link[i]].status == 3)
		{
			matrice[queu[0]][board.rooms[queu[0]].link[i]] = 2;
			matrice[board.rooms[queu[0]].link[i]][queu[0]] = 2;
			queu[++j] = board.rooms[queu[0]].link[i];
			board.rooms[board.rooms[queu[0]].link[i]].status = 1;
			board.rooms[board.rooms[queu[0]].link[i]].prev =
			&board.rooms[queu[0]];
			board.rooms[board.rooms[queu[0]].link[i]].cp =
			&board.rooms[queu[0]];
		}
	}
	return (j);
}

static	int li_bfs_type_b(t_board board, int **matrice, int *queu, int j)
{
	int i;

	i = -1;
	while (++i < board.rooms[queu[0]].count_link)
	{
		if (board.rooms[board.rooms[queu[0]].link[i]].status == 2
		&& matrice[queu[0]][board.rooms[queu[0]].link[i]] == 1)
		{
			matrice[queu[0]][board.rooms[queu[0]].link[i]] = 3;
			matrice[board.rooms[queu[0]].link[i]][queu[0]] = 3;
			li_priority_queu(queu + i, board.rooms[queu[0]].link[i]); //queu + i??
			j++;
			board.rooms[board.rooms[queu[0]].link[i]].status = 7;
			board.rooms[board.rooms[queu[0]].link[i]].cp =
			&board.rooms[queu[0]];
		}
	}
	return (j);
}

static	int li_bfs_type_c(t_board board, int **matrice, int *queu, int j)
{
	int i;

	i = -1;
	while (++i < board.rooms[queu[0]].count_link)
	{
		if (board.rooms[board.rooms[queu[0]].link[i]].status == 2
		&& matrice[queu[0]][board.rooms[queu[0]].link[i]] == 4)
		{
			//ft_printf("{red}BIP BIP BIP BIP BIP BIP\n{}");
			matrice[queu[0]][board.rooms[queu[0]].link[i]] = 6;
			matrice[board.rooms[queu[0]].link[i]][queu[0]] = 7;
			li_priority_queu(queu + i, board.rooms[queu[0]].link[i]); //queu + i??
			j++;
			board.rooms[board.rooms[queu[0]].link[i]].status = 8;
			board.rooms[board.rooms[queu[0]].link[i]].cp =
			&board.rooms[queu[0]];
		}
	}
	return (j);
}

int	li_bfs_body(t_board board, int **matrice, int *queu, int j)
{
	int i;
	int save;

	i = -1;
	save = j;
	//ft_printf("On regarde actuellement la sall %d et status de queu = %d\n", queu[0], board.rooms[queu[0]].status);
	//ft_printf("{yellow}son prev = %d\n{}", board.rooms[queu[0]].prev->index);
	if (board.rooms[queu[0]].status == 5)
	{
		j = li_bfs_type_c(board, matrice, queu, j);
		return (j - save);
	}
	if ((j = li_bfs_type_a(board, matrice, queu, j)) != save)
		return (j - save);
	if ((j = li_bfs_type_b(board, matrice, queu, j)) != save)
		return (j - save);
	//ft_printf("?.?\n");
	return (0);
}
