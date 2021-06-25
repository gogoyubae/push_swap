/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x2x.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:09:30 by yubae             #+#    #+#             */
/*   Updated: 2021/06/25 20:00:50 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		init_val(t_val *val)
{
	val->ra = 0;
	val->rb = 0;
	val->pa = 0;
	val->pb = 0;
}

t_val		a2b_sort(t_list *a, t_list *b, int cnt, int p)
{
	int		i;
	t_val	val;

		init_val(&val);
	while (cnt-- > 0)
	{
		if (p <= a->head->cont)
		{
			ra(a);
			val.ra++;
		}
		else
		{
			pb(a, b);
			val.pb++;
		}
	}
	i = 0;
	if (count_node(a) != val.ra)
	{
		while (i++ < val.ra)
			rra(a);	
	}
	return (val);
}

void		a2b(t_info *info, t_list *a, t_list *b, int cnt)
{
	int		p;
	t_val	val;
	//printf("----------a2b\n");

	if (cnt < 3 || (cnt <= 3 && info->node <= 5))
		return (a_less3(info, cnt));
	p = pivot(a, cnt);
	val = a2b_sort(a, b, cnt, p);
	//printf("val.ra %d\n", val.ra);
	//printf("val.pb %d\n", val.pb);
	a2b(info, a, b, val.ra);
	b2a(info, a, b, val.pb);
	//printf("a  "); display(a);
	//printf("b  "); display(b);
}

t_val		b2a_sort(t_list *a, t_list *b, int cnt, int p)
{
	int		i;
	t_val	val;

	init_val(&val);
	while (cnt-- > 0)
	{
		if (p >= b->head->cont)
		{
			rb(b);
			val.rb++;
		}
		else
		{
			pa(b, a);
			val.pa++;
		}
	}
	i = 0;
	if (count_node(b) != val.rb)
	{
				//printf("val.rb %d", val.rb);
		while (i++ < val.rb)
			rrb(b);
		}
	return (val);
}

void		b2a(t_info *info, t_list *a, t_list *b, int cnt)
{
	int		p;
	t_val	val;
	//printf("----------b2a\n");

	if (cnt < 3 || (cnt <= 3 && info->node <= 5))
		return (b_less3(info, cnt));
	p = pivot(b, cnt);
	val = b2a_sort(a, b, cnt, p);
	
	//printf("val.pa %d\n", val.pa);
	//printf("val.rb %d\n", val.rb);
	//printf("a  "); display(a);
	//printf("b  "); display(b);

	a2b(info, a, b, val.pa);
	b2a(info, a, b, val.rb);
//printf("a  "); display(a);
	//printf("b  "); display(b);

}
