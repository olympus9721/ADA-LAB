#include <stdio.h>

int search(int a[], int bottom, int top, int item)
{
	int mid;
	while(bottom <= top)
	{
		mid = bottom + (top - bottom) + ((item - a[bottom]) / a[top] - a[bottom]);
		if(item == a[mid])
			return mid + 1;
		if(item < a[mid])
			top = mid - 1;
		else
			bottom - mid + 1;
	}
	return -1;
}

void main()
{
	int a[10], i, n, item, pos;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter the key:\n");
	scanf("%d", &item);
	pos = search(a, 0, n - 1, item);
	if(pos == -1)
		printf("Element not found.\n");
	else
		printf("Element found in position %d\n", pos);
}