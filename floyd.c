#include <stdio.h>



int min1(int a, int b)
{
	return (a < b)? a : b;
}

void all_paths(int cost[5][5], int a[5][5], int n)
{
	int i , j, k;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			a[i][j] = cost[i][j];

	for(k = 1; k <= n; k++)
		for(i = 0; i <= n; i++)
			for(j = 0; j <= n; j++)
				a[i][j] = min1(a[i][j], a[i][k] + a[k][j]);	

}



void main()
{
	int cost[5][5], a[5][5];
	int i, j, n;
	printf("Enter the number of vertices:\n");
	scanf("%d", &n);
	printf("Enter adjacency matrix:\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &cost[i][j]);

	all_paths(cost, a, n);

	printf("Shortes path is:\n");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
			printf("%d  ", a[i][j]);
		printf("\n");
	}
}