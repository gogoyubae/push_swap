/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:38:57 by yubae             #+#    #+#             */
/*   Updated: 2021/06/24 20:32:54 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			pivot(t_list *list, int cnt)
{
	int		i;
	int		pivot;
	int		arr[cnt];
	t_node	*tmp;

	i = 0;
	tmp = list->head;
	while (i < cnt)
	{
		arr[i] = tmp->cont;
		tmp = tmp->next;
		i++;
	}
	quicksort(arr, 0, cnt - 1);
	pivot = arr[i / 2];
	return (pivot);
}

void		qs_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int			qs_partition(int arr[], int l, int r)
{
	int		i;
	int		j;
	int		pivot;

	i = l - 1;
	j = l;
	pivot = arr[r];
	while (j < r)
	{
		if (arr[j] <= pivot)
		{
			i++;
			qs_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	qs_swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

void		quicksort(int arr[], int l, int r)
{
	int		p;

	if (l < r)
	{
		p = qs_partition(arr, l, r);
		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	else
		return ;
}
//
//int main()
//{
//	int arr[5] = {4, 1, 3, 2, 5};
//	for(int i = 0; i < 5; i++)
//	quicksort(arr, 0, 4);
//
//	for(int i = 0; i < 5; i++)
//}
//
