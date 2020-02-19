/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:10:51 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 15:49:59 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (*s)
		s++;
	while (*s != c)
		s--;
	return ((char *)s);
}
