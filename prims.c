#include <stdio.h>

int a, b, u, v, i, j, n, ne = 1;
int visited[5] = {0}, min, mincost = 0, cost[5][5];

void main()
{
	printf("Enter the number of vertices:\n");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = 999;
		}

	visited[1] = 1;
	while(ne < n)
	{
		for(i = 1, min = 999; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(cost[i][j] < min)
					if(visited[i] != 0)
					{
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}

		if(visited[u] == 0 || visited[v] == 0)
		{
			printf("Edge %d: ( %d to %d) cost: %d\n", ne++, a, b, min);
			mincost += min;
			visited[b] = 1;
		}

		cost[a][b] = cost[b][a] = 999;
	}
	printf("Minimum cost = %d \n", mincost);

}