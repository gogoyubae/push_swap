/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x2x.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 20:31:46 by yubae             #+#    #+#             */
/*   Updated: 2021/06/20 20:51:11 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	init_val(t_val *val)
{
	val->ra = 0;
	val->rb = 0;
	val->pa = 0;
	val->pb = 0;
}

t_val	a2b_sort(t_list *a, t_list *b, int cnt, int p)
{		
	int		i;
	t_val	val;

	init_val(&val);
	while (cnt-- > 0)
	{
		if (p < a->head->cont)
		{
			rab(a);
			val.ra++;
		}
		else
		{
			pab(a, b);
			val.pb++;
		}
	}
	i = 0;
	if (count_node(a) != val.ra)
	{
		while (i++ < val.ra)
		rrab(a);
	}
	return (val);
}

void	a2b(t_info *info, t_list *a, t_list *b, int cnt)
{
	int		p;
	t_val	val;

	if (cnt <= 3)
		return (a_less3(info, cnt));
	p = pivot(a, cnt);
	val = a2b_sort(a, b, cnt, p);
	a2b(info, a, b, val.ra);
	b2a(info, a, b, val.pb);
}

t_val	b2a_sort(t_list *a, t_list *b, int cnt, int p)
{		
	int		i;
	t_val	val;

	init_val(&val);
	while (cnt-- > 0)
	{
		if (p > b->head->cont)
		{
			rab(b);
			val.rb++;
		}
		else
		{
			pab(b, a);
			val.pa++;
		}
	}
	i = 0;
	if (count_node(b) != val.rb)
	{
		while (i++ < val.rb)
		rrab(b);
	}
	return (val);
}

void	b2a(t_info *info, t_list *a, t_list *b, int cnt)
{
	int		p;
	t_val	val;

	if (cnt <= 3)
		return (b_less3(info, cnt));
	p = pivot(b, cnt);
	val = b2a_sort(a, b, cnt, p);
	a2b(info, a, b, val.pa);
	b2a(info, a, b, val.rb);
}
