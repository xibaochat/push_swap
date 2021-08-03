#include "push_swap.h"

void	swap(int* x, int* y)
{
    int temp;

	temp = *x;
    *x = *y;
    *y = temp;
}

#include <stdio.h>

int		sort_and_get_mid_nb(int *arr, int n)
{
    int	i;
	int	j;
	int	min_idx;
	int	mid;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap(&arr[min_idx], &arr[i]);
		i++;
	}
	mid = arr[n/2];
	return (mid);
}
