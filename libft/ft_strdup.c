/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:53:56 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 15:44:54 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		cpt;
	int		src_size;
	char	*dest;

	src_size = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (src_size + 1));
	if (dest == NULL)
		return (NULL);
	cpt = 0;
	while (src[cpt] != '\0')
	{
		dest[cpt] = src[cpt];
		cpt++;
	}
	dest[src_size] = '\0';
	return (dest);
}
