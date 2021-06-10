/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:23:42 by yubae             #+#    #+#             */
/*   Updated: 2021/01/06 20:53:15 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *dst, int val, size_t size)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	c;

	i = 0;
	p = (unsigned char *)dst;
	c = (unsigned char)val;
	while (i < size)
	{
		if (p[i] == c)
			return ((void *)dst + i);
		i++;
	}
	return (0);
}
