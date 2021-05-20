/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:13:47 by yubae             #+#    #+#             */
/*   Updated: 2021/01/16 20:15:31 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	if (p1 == 0 && p2 == 0)
		return (0);
	if (p1 < p2)
	{
		while (i < size)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	while (i < size)
	{
		p1[size - 1 - i] = p2[size - 1 - i];
		i++;
	}
	return (dst);
}
