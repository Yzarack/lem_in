/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:55:56 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 15:04:58 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*dest;

	if (s == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	dest = (char *)malloc(size + 1);
	if (dest == NULL)
		return (NULL);
	while (i < size)
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
