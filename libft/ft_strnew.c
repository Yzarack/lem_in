/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:41:41 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/09 23:12:41 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*dest;

	if ((dest = (char *)malloc(sizeof(char) * size + 1)) == 0)
		return (NULL);
	ft_memset(dest, (int)'\0', size + 1);
	return (dest);
}
