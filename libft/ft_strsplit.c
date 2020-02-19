/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:43:19 by lufrar            #+#    #+#             */
/*   Updated: 2019/11/19 17:12:02 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char		**ft_strsplit(char const *s, char c)
{
	int		nb_words;
	char	**dest;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	nb_words = ft_get_nb_words(s, c);
	dest = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (dest == NULL)
		return (NULL);
	while (nb_words > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		dest[i] = ft_strsub(s, 0, ft_word_size(s, c));
		if (dest[i] == NULL)
			return (NULL);
		s = s + ft_word_size(s, c);
		s++;
		i++;
		nb_words--;
	}
	dest[i] = NULL;
	return (dest);
}
