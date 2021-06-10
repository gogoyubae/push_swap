/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:07:06 by yubae             #+#    #+#             */
/*   Updated: 2021/01/13 14:39:20 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)str;
	while (i < ft_strlen(str))
	{
		if (p[i] == c)
			return (p + i);
		i++;
	}
	if (c == 0)
		return (p + i);
	return (0);
}
