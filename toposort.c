#include <stdio.h>

int a[10][10], reach[10], n;

void dfs(int v)
{
	int i;
	reach[v] = 1;
	for(i = 1; i <= n; i++)
		if(a[v][i] && reach[i] == 0)
		{
			
			printf("%d --> %d\n", v, i);
			dfs(i);
			
		}
}


void main()
{
	int i, j, count = 0;
	printf("Enter the number of vertices:\n");
	scanf("%d", &n);
	for(i = 0; i <= n; i++)
	{
		reach[i] = 0;
		for(j = 0; j <= n; j++)
			a[i][j] = 0;
	}
	printf("Enter adjacency matrix:\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	dfs(1);

	for(i = 1; i <= n; i++)
		{
			if(reach[i])
				count++;
		}

	if(count == n)
		printf("Graph is connected.\n");
	else
		printf("Graph is not connected.\n");

}