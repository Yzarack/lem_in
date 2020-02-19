/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:42:20 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 15:43:03 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;
	unsigned char	c_cpy;

	s_cpy = (unsigned char *)s;
	c_cpy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_cpy[i] == c_cpy)
			return (s_cpy + i);
		i++;
	}
	return (NULL);
}
