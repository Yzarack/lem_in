/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:44:19 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 15:51:13 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	cpt;

	cpt = 0;
	if (n == 0)
		return (0);
	while (s1[cpt] != '\0' && s2[cpt] != '\0' && s1[cpt] == s2[cpt]
			&& cpt < n - 1)
		cpt++;
	return ((unsigned char)s1[cpt] - (unsigned char)s2[cpt]);
}
