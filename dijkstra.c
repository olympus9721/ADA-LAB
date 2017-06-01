#include <stdio.h>

void dijk(int g[5][5], int n, int startnode);

void main()
{
	int g[5][5], n, i, j, u;
	printf("Enter the number of vertices:\n");
	scanf("%d", &n);
	printf("Enter adjacency matrix:\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &g[i][j]);

	printf("Enter the starting node:\n");
	scanf("%d", &u);
	dijk(g, n, u);

}

void dijk(int g[5][5], int n, int startnode)
{
	int cost[5][5], distance[5], pred[5];
	int visited[5], count, mindistance, nextnode, i, j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(g[i][j] == 0)
				cost[i][j] = 999;
			else
				cost[i][j] = g[i][j];

	for(i = 1; i <= n; i++)
	{
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	while(count < n)
	{
		mindistance = 999;
		for(i = 1; i <= n; i++)
			if(distance[i] < mindistance && visited[i] == 0)
			{
				mindistance = distance[i];
				nextnode = i;
			}
		visited[nextnode] = 1;
		for(i = 1; i <= n; i++)
			if(!visited[i])
				if(distance[i] > mindistance + cost[nextnode][i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
			count++;
	}

	for(i = 1; i <= n; i++)
		if(i != startnode)
		{
			printf("\nDistance for %d = %d \n",i, distance[i]);
			printf("Path : %d ", i);
			j = i;
			do
			{
				j = pred[j];
				printf(" <-- %d ", j);
			}
			while(j != startnode);

		}
			
}