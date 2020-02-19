/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:56:02 by lufrar            #+#    #+#             */
/*   Updated: 2020/02/14 16:40:52 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

int		ft_read_in_char(char **line, char **save, int value, char *tmp)
{
	if (*save != NULL && *save[0] == '\0')
	{
		free(*save);
		*save = NULL;
		return (0);
	}
	if (value == -1 && *save != NULL && *save[0] != '\0')
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (1);
	}
	else if (ft_strchrint(*save, '\n') != -1)
	{
		if (!(*line = (char *)malloc(sizeof(char) * (value + 1))))
			return (-1);
		ft_bzero(*line, value + 1);
		*line = ft_strncat(*line, *save, value);
		tmp = *save;
		*save = ft_strdup(ft_strchr(*save, '\n'));
		free(tmp);
		*save = ft_strcpy(*save, *save + 1);
	}
	return (1);
}

char	*ft_inner_gnl(const int fd, char **line)
{
	char *buff;

	if (fd < 0 || line == NULL)
		return (NULL);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	return (buff);
}

int		ft_get_next_line(const int fd, char **line)
{
	static char *save = NULL;
	int			ret;
	char		*buff;
	char		*tmp;

	ret = 1;
	if ((buff = ft_inner_gnl(fd, line)) == NULL)
		return (-1);
	if (save == NULL)
		save = ft_strdup("");
	while (ret != 0 && ft_strchrint(save, '\n') == -1)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
		{
			free(buff);
			free(save);
			return (-1);
		}
		buff[ret] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free(buff);
	ret = ft_strchrint(save, '\n');
	return (ft_read_in_char(line, &save, ret, tmp));
}
