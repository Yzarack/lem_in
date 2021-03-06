/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbegins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:49:10 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/03 14:06:25 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strbegins(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s2)) == 0);
}
