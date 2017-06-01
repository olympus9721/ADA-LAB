#include <stdio.h>
int a[10][10];

void main()
{
	int i, j, k, n;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	printf("Enter adjacency martix:\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				a[i][j] = a[i][j] || a[i][k] && a[k][j];

	printf("Transitive closure is :\n");

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
			printf("%d  ", a[i][j]);
		printf("\n");
	}
}