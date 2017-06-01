#include <stdio.h>

void rlinearsearch(int a[], int x, int n, int key)
{
	if(x == n)
	{
			printf("Element not found.\n");
			return;
	}

	else
	{
		if(a[x] == key)
		{
			printf("Element found in position: %d \n",x + 1);
			return;
		}
		else
			rlinearsearch(a, x + 1, n, key);
	}
}

void main()
{
	int a[10], n, key, i;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Enter the key element:\n");
	scanf("%d", &key);

	rlinearsearch(a, 0, n, key);
}