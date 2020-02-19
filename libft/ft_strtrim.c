/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:59:00 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 11:55:51 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int	start;
	int	end;

	if (s == NULL)
		return ((char *)s);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == ',' || s[start] == '\n' ||
				s[start] == '\t') && s[start] != '\0')
		start++;
	if (s[start] == '\0')
		return (ft_strdup((char *)s + start));
	while ((s[end] == ' ' || s[end] == ',' || s[end] == '\n' ||
				s[end] == '\t') && end > 0)
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
