/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:34:14 by yubae             #+#    #+#             */
/*   Updated: 2021/01/16 20:09:58 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (i > size)
		return (ft_strlen(src) + size);
	else
	{
		while (src[j] && i + j + 1 < size)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
		return (ft_strlen(src) + i);
	}
}
