/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:31:45 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 15:42:12 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	const char	*src_cpy;
	char		*dest_cpy;

	src_cpy = (const char *)src;
	dest_cpy = (char *)dest;
	i = 0;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		if (src_cpy[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
