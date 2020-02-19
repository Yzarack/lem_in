/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 01:01:24 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/14 02:19:15 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_inner_join_free(char *s1, char *s2, int del)
{
	free(s1);
	if (del == 1)
		free(s2);
}

char	*ft_strjoinfree(char *s1, char *s2, int del)
{
	char	*dest;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = 0;
	if ((dest = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 10))) == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	ft_inner_join_free(s1, s2, del);
	return (dest);
}
