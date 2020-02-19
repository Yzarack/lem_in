/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:21:09 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 15:50:46 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	needle_size;

	if (*haystack == '\0')
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	needle_size = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= needle_size)
	{
		if (*needle == *haystack && ft_memcmp(haystack, needle, needle_size)
				== 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
