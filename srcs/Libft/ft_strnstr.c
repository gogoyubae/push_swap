/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:34:14 by yubae             #+#    #+#             */
/*   Updated: 2021/01/17 21:59:40 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	big_len;
	size_t	little_len;
	char	*p;

	i = 0;
	big_len = ft_strlen(big);
	little_len = ft_strlen(lit);
	p = (char *)big;
	while (i + little_len <= len && i + little_len <= big_len)
	{
		if (ft_strncmp(big + i, lit, little_len) == 0)
			return (p + i);
		i++;
	}
	return (0);
}
