/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:36:28 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/10 13:37:46 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprime(int nb)
{
	int	cpt;

	cpt = 2;
	if (nb <= 1)
		return (0);
	while (cpt < nb)
	{
		if (nb % cpt == 0)
			return (0);
		cpt++;
	}
	return (1);
}
