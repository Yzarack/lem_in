/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:40:16 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/14 13:28:56 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LEM_IN_H
# define __FT_LEM_IN_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_djik
{
	char			*name;
	int				special;
	int				distance;
	int				bfs_end;
	int				ants_in_path;
	int				input;
	int				output;
	int				status;
	int				end_path;
	struct s_djik	**from;
	struct s_djik	**link;
	struct s_djik	*next;
}				t_djik;

typedef struct	s_ants
{
	int				index;
	int				print;
	t_djik			*current_room;
	struct s_ants	*next;
}				t_ant;

typedef struct	s_map
{
	char	**rooms_names;
	char	**tunnels_split;
	char	*room_list;
	char	*room_list_disp;
	char	*tunnels;
	char	*tunnels_disp;
	char	*start;
	char	*end;
	int		check[2];
	int		nb_rooms;
	int		nb_ants;
	int		path_index;
	int		current_room;
	int		step;
	int		ant_index;
}				t_map;

int				ft_rooms_tunnels(t_map *map);
void			ft_rooms(t_map *map, char *line);
void			ft_tunnels(t_map *map, char *line);
void			ft_check_rooms(t_map *map);

/*
** TOOLS
*/

int				ft_is_str_empty(char *s);
char			*ft_join_str(char *s1, char *s2, int clean);
void			ft_free_str_error(char **str, int error);
void			ft_exit_lem_in(t_map *map, int error);
void			ft_get_nb_ants(t_map *map, char *line);
int				ft_add_elem(t_djik **djik, char *name, int end);
t_djik			*ft_init_start(t_map *map);
t_djik			**ft_djikdup(t_djik **djik);
int				ft_is_in_path(t_djik *djik, char *name);
char			*ft_find_end(char *room_names);
int				ft_init_map(t_map **map);
t_map			*ft_init_map_2(t_map *map);
char			*ft_strstr_custom(const char *haystack, char *needle);
void			ft_free_ants(t_ant *ants);
void			ft_delete_room(t_djik *djik);
void			ft_delete_from(t_djik *djik, t_djik *del);
void			ft_delete_link(t_djik *djik, t_djik *del);
int				ft_add_from(t_djik *djik, t_djik *from);
void			ft_finish_djik(t_djik *djik, t_map *map);
void			ft_swap_djik(t_djik *djik, t_djik *tmp);
void			ft_reset(t_djik *djik);
/*
** SOLVE
*/

int				ft_resolve_karp(t_map *map);
char			*ft_find_link(t_map *map, char *name, t_djik *d, int i);
void			ft_remove_line(t_map *map, int i);
int				ft_add_link(t_djik *djik, t_djik *link);
t_ant			*ft_create_ant(t_djik *current_room, int *index, int *nb_ants);
void			ft_count_end(t_djik *djik);
void			ft_endbfs(t_djik *save);
int				ft_find_path(t_djik *djik, t_djik *tmp, int rev);
void			ft_insertion_sort_link(t_djik *djik);
void			ft_insertion_sort_from(t_djik *djik, t_djik *tmp);
void			ft_delete_path(t_djik *djik);

/*
**PRINT
*/

void			ft_print(t_djik *djik, int nb_ants);
int				ft_get_path_len(t_djik *djik);
t_djik			**ft_sort_path(t_djik **djik, int *paths_lenght, int nb_path);
int				ft_send_to_path(int *paths_lenght, int current_path,
				int nb_ants);
int				ft_get_nb_paths(t_djik *arg);
int				ft_check_ants_in_path(t_ant *ant);
int				*ft_len_tab(t_djik **paths, int nb_path);
t_djik			**ft_get_paths(t_djik *djik, int nb_path);
void			ft_display_and_advance(t_ant *begin);
void			ft_display_ants(t_ant *ant);
void			ft_advance_ants(t_ant *buff);
int				ft_left_to_print(t_ant *begin);

#endif
