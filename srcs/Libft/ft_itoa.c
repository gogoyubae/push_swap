/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:02:40 by yubae             #+#    #+#             */
/*   Updated: 2021/01/16 20:58:42 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			num_len(long long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long long n)
{
	char	*p;
	int		i;
	int		len;

	i = 0;
	len = num_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		p[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	p[len] = '\0';
	return (p);
}
