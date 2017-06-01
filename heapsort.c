#include <stdio.h>

void heapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while(j <= n)
	{
		if(j < n && a[j + 1] > a[j])
			j = j + 1;
		if(temp > a[j])
			break;
		else
			if(temp <= a[j])
			{
				a[j / 2] = a[j];
				j = 2 * j;
			}
	}
	a[j / 2] = temp;
	return;
}

void heapsort(int a[], int n)
{
	int i, temp;
	for(i = n; i >= 2; i--)
	{
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		heapify(a, 1, i -1);
	}
}

void maxheap(int a[], int n)
{
	int i;
	for(i = n / 2; i >= 1; i--)
		heapify(a, i, n);
}

void main()
{
	int a[10], i, n, v;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	maxheap(a, n);
	heapsort(a, n);
	printf("Sorted array is:\n");
	for(i = 1; i <= n; i++)
		printf("%d  ",a[i]);
}