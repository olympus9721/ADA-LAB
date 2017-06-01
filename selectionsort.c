#include <stdio.h>
#include <stdlib.h>

void selectionsort(int a[], int n)
{
	int i, j, temp, min;
	for(i = 0; i < n; i++)
	{
		min = a[i];
		for(j = i + 1; j < n; j++)
		{
			if(a[j] < min)
			{
				min = a[j];
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
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

	selectionsort(a, n);

	printf("\n");
	printf("Elements after sorting:\n");
	for (int i = 0; i < n; i++)
		printf("%d  ",a[i]);
	printf("\n");
}