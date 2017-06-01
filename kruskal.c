#include <stdio.h>

int a, b, u, v, i, j, n, ne = 1;
int parent[5], min, mincost = 0, cost[5][5];

int find(int i)
{
	while(parent[i])
		i = parent[i];
	return i;
}

int uni(int i, int j)
{
	if(i != j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}

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

	while(ne < n)
	{
		for(i = 1, min = 999; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(cost[i][j] < min)
					{
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}

		u = find(u);
		v = find(v);
		if(uni(u, v))
		{
			printf("Edge %d: ( %d to %d) cost: %d\n", ne++, a, b, min);
			mincost += min;
		}

		cost[a][b] = cost[b][a] = 999;
	}
	printf("Minimum cost = %d \n", mincost);

}