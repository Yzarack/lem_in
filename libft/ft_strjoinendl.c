/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinendl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:55:00 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/13 17:55:59 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinendl(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = ft_strlen(s2);
	i = 0;
	if ((dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + j + 2))) == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}
