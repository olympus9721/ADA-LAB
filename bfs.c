#include <stdio.h>

int a[5][5], q[5], visited[5], n, i, j, f = 0, r = -1;

void bfs(int v)
{
	for(i = 1; i <= n; i++)
		if(a[v][i] && !visited[i])
   			q[++r] = i;
 	if(f <= r)
 	{
  		visited[q[f]] = 1;
  		bfs(q[f++]);
 	}
}
void main()
{
	int v;
 	printf("Enter the number of vertices:\n");
 	scanf("%d",&n);
 	for(i = 1; i <= n; i++)
 	{
 		q[i] = 0;
  		visited[i] = 0;
 	}
 	printf("Enter graph data in matrix form:\n");
 		for(i = 1; i <= n; i++)
  			for(j = 1; j <= n; j++)
   				scanf("%d",&a[i][j]);
 	printf("Enter the starting vertex:\n");
 	scanf("%d",&v);
 	bfs(v);
 	printf("The node which are reachable are:\n");
 	for(i = 1; i <= n; i++)
  		if(visited[i])
   			printf("%d\t",i);
  
}