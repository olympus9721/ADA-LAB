#include <stdio.h>

void bsearch(int a[], int key, int low, int high)
{
	int mid;
	if(low > high)
	{
		printf("Element not found.\n");
		return;
	}
	else
	{
		mid = (low + high) / 2;
		if(a[mid] == key)
		{
			printf("Element found in the position: %d\n", mid + 1);
			return;
		}
		else
			if(key < a[mid])
				bsearch(a, key, low, mid - 1);
			else
				bsearch(a, key, mid + 1, high);
	}
}

void main()
{
	int n, a[10], i, key;

	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter the key:\n");
	scanf("%d", &key);

	bsearch(a, key, 0, n - 1);
}