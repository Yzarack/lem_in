/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:39:42 by lufrar            #+#    #+#             */
/*   Updated: 2018/11/06 20:24:44 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	cpt;

	cpt = 0;
	while (s1[cpt] != '\0' && s2[cpt] != '\0' && s1[cpt] == s2[cpt])
		cpt++;
	return ((unsigned char)(s1[cpt]) - (unsigned char)(s2[cpt]));
}
