/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:45:31 by yubae             #+#    #+#             */
/*   Updated: 2021/01/16 21:03:31 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			cnt_c(const char *s, char c, size_t len)
{
	size_t		i;
	size_t		cnt;

	i = 0;
	cnt = 0;
	while (i < len)
	{
		if (s[i] != c && s[i] != 0)
		{
			cnt++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		else if (s[i] != 0)
			i++;
	}
	return (cnt);
}

char			**res_free(char **res, size_t cnt)
{
	while (cnt > 0)
	{
		cnt--;
		free(res[cnt]);
	}
	free(res);
	return (0);
}

void			do_split(const char *s, char c, char **res)
{
	size_t		i;
	size_t		j;
	size_t		bgin;

	i = 0;
	j = 0;
	while (s[j] != 0)
	{
		if (s[j] != c && s[j] != 0)
		{
			bgin = j;
			while (s[j] != c && s[j] != 0)
				j++;
			if (!(res[i] = malloc(sizeof(char) * (j - bgin + 1))))
			{
				res_free(res, i);
				return ;
			}
			ft_strlcpy(res[i], &s[bgin], j - bgin + 1);
			i++;
		}
		else if (s[j] != 0)
			j++;
	}
}

char			**ft_split(const char *s, char c)
{
	char		**res;
	size_t		cnt;
	size_t		len;

	res = 0;
	len = ft_strlen(s);
	if (s == 0 || len == 0)
	{
		if (!(res = malloc(sizeof(char *))))
			return (0);
		res[0] = 0;
		return (res);
	}
	cnt = cnt_c(s, c, len);
	if (!(res = malloc(sizeof(char *) * (cnt + 1))))
		return (0);
	res[cnt] = 0;
	if (cnt == 1)
		res[0] = ft_strtrim(s, &c);
	if (cnt != 0 && cnt != 1)
		do_split(s, c, res);
	return (res);
}
