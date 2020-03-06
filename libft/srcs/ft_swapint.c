/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:51:27 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/05 23:52:59 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_swapint(int *a, int *b)
{
	int		swp;

	swp = (*a);
	(*a) = (*b);
	(*b) = swp;
}