/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:16:22 by yubae             #+#    #+#             */
/*   Updated: 2021/01/18 02:24:22 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s);
	if (start < i)
	{
		if (!(p = malloc(sizeof(char) * (len + 1))))
			return (0);
		ft_strlcpy(p, s + start, len + 1);
		return (p);
	}
	else
		return (ft_strdup(""));
}
