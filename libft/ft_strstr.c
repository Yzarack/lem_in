/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:21:09 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 15:50:21 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	needle_size;

	needle_size = ft_strlen(needle);
	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		while (needle[j] == haystack[i + j])
		{
			if (j == needle_size - 1)
				return ((char *)haystack + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
