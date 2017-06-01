#include <stdio.h>
#include <stdlib.h>

int partition(int [], int, int);
void sort(int a[], int start, int end)
{
	if(start < end)
	{
		int p;
		p = partition(a, start, end);
		sort(a, start, p - 1);
		sort(a, p + 1, end);
	}
}

int partition(int a[], int start, int end)
{
	int pivot, pindex, temp, i;
	pivot = a[end];
	pindex = start;
	for(i = start; i < end; i++)
	{
		if(a[i] <= pivot)
		{
			temp = a[i];
			a[i] = a[pindex];
			a[i] = temp;
			pindex++;
		}
	}
	temp = a[pindex];
	a[pindex] = a[end];
	a[end] = temp;
	return pindex;
}

void main()
{
	int a[10], n, i;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	printf("Enter unsorted elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, 0, n - 1);

	printf("Elements after sorting:\n");
	for(i = 0; i < n; i++)
		printf("%d  ", a[i]);
}