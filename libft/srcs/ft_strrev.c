/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:03:52 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/25 20:05:15 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_strrev(char *str)
{
	char	*end;
	char	swp;

	end = str;
	while (*end != '\0')
		end++;
	end--;
	while (str < end)
	{
		swp = *str;
		*str = *end;
		*end = swp;
		str++;
		end--;
	}
}
