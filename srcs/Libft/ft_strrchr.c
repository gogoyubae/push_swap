/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:20:00 by yubae             #+#    #+#             */
/*   Updated: 2021/01/05 13:56:33 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*p;

	i = ft_strlen(str);
	p = (char *)str;
	if (c == 0)
		return (p + i);
	while (i > 0)
	{
		if (p[i - 1] == c)
		{
			return (p + i - 1);
		}
		i--;
	}
	return (0);
}
