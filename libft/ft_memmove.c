/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:36:11 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 16:53:52 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned long	long_dst;
	unsigned long	long_src;

	i = 0;
	long_dst = (unsigned long)dest;
	long_src = (unsigned long)src;
	if (long_dst > long_src)
	{
		while (n - i > 0)
		{
			i++;
			((char *)dest)[n - i] = ((char *)src)[n - i];
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
