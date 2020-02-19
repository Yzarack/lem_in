/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:23:37 by lufrar            #+#    #+#             */
/*   Updated: 2019/04/10 16:16:56 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_get_nb_words(char const *str, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (i == 1 && *str == c)
			i = 0;
		if (i == 0 && *str != c)
		{
			i = 1;
			nb_words++;
		}
		str++;
	}
	return (nb_words);
}
