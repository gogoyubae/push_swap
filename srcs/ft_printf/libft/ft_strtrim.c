/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:38:04 by yubae             #+#    #+#             */
/*   Updated: 2021/01/16 21:01:11 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*p;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	while (s1[i] != 0 && ft_strchr(set, s1[i]))
		i++;
	if (i == len)
		return (ft_strdup(""));
	else
	{
		while (s1[len - j - 1] != 0 && ft_strrchr(set, s1[len - j - 1]))
			j++;
		if (!(p = malloc(sizeof(char) * (len - i - j + 1))))
			return (0);
		ft_strlcpy(p, s1 + i, len - i - j + 1);
		return (p);
	}
}
