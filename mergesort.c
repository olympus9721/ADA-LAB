#include <stdio.h>
#include <stdlib.h>

void sort(int [], int, int, int);
void merge(int a[], int min, int max)
{
	int mid;
	if(min < max)
	{
		mid = (min + max) / 2;
		merge(a, min, mid);
		merge(a, mid + 1, max);
		sort(a, min, mid, max);
	}
}

void sort(int a[], int min, int mid, int max)
{
	int temp[10], i, j, k, m;
	j = min;
	m = mid + 1;
	for(i = min; j <= mid && m <= max; i++)
	{
		if(a[j] <= a[m])
		{
			temp[i] = a[j];
			j++;
		}
		else
		{
			temp[i] = a[m];
			m++;
		}
	}
	if(j > mid)
	{
		for(k = m; k <= max; k++)
		{
			temp[i] = a[k];
			i++;
		}
	}
	else
	{
		for(k = j; k <= mid; k++)
		{
			temp[i] = a[k];
			i++;
		}
	}
	for(k = min; k <= max; k++)
		a[k] = temp[k];
} 

void main()
{
	int a[10], n, i;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	printf("Enter unsorted elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	merge(a, 0, n - 1);

	printf("\n");
	printf("Elements after sorting:\n");
	for (int i = 0; i < n; i++)
		printf("%d  ",a[i]);
	printf("\n");
}