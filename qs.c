/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:38:57 by yubae             #+#    #+#             */
/*   Updated: 2021/06/01 17:13:21 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void swap(int *a, int *b)
{
	int *tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int i = l - 1;

	printf("pivot : %d\n", pivot);
	for (int j = l; j < r; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

void quicksort(int arr[], int l, int r)
{
	if (l < r)
	{
		int p = partition(arr, l, r);

		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
	else
		return;
}

int main ()
{
	int arr[6] = {7,2,5,1,3,4};

	quicksort(arr, 0, 5);
	for (int i = 0; i < 6; i++)
		printf("arr[%d]:%d  ", i, arr[i]);

}
