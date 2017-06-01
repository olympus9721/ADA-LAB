#include <stdio.h>

void insertion(int a[], int n)
{
	int i, value, h;
	for( i = 1; i < n; i++)
	{
		value = a[i];
		h = i;
		while(h > 0 && a[h - 1] > value)
		{
			a[h] = a[h-1];
			h = h - 1;
		}
		a[h] = value;
	}
}

void main()
{
	int a[10], n, i;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	printf("Enter the unsorted elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	insertion(a, n);

	printf("\n");
	printf("Elements after sorting:\n");
	for (int i = 0; i < n; i++)
		printf("%d  ",a[i]);
	printf("\n");
}
