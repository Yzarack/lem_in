/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:23:01 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/29 13:43:52 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	int		n_len;
	int		is_neg;
	char	*dest;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_len = ft_int_len(n);
	dest = (char *)malloc(sizeof(char) * n_len + 1);
	if (dest == NULL)
		return (NULL);
	dest[n_len] = '\0';
	n_len--;
	is_neg = 0;
	if (n < 0)
	{
		dest[0] = '-';
		is_neg = 1;
		n = -n;
	}
	dest = ft_getnb(dest, n_len, is_neg, n);
	return (dest);
}
