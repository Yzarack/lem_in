/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:32:43 by lufrar            #+#    #+#             */
/*   Updated: 2017/11/09 11:39:26 by lufrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*to_malloc;

	if ((to_malloc = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(to_malloc, size);
	return (to_malloc);
}
