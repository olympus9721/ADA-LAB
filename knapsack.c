#include <stdio.h>

int v[10][10];

int max1(int a, int b)
{
	return (a > b)? a : b;
}

void main()
{
	int i, j, n, max, p[5], w[5];
	printf("Enter the number of items:\n");
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		printf("Enter weight and profit of item %d :", i);
		scanf("%d %d", &w[i], &p[i]);
	}
	printf("Enter the capacity of the knapsack:\n");
	scanf("%d", &max);
	for(i = 0; i <= n; i++)
		v[i][0] = 0;
	for(j = 0; j <= max; j++)
		v[0][j] = 0;

	for(i = 1; i <= n; i++)
		for(j = 1; j <= max; j++)
		{
			if(w[i] > j)
				v[i][j] = v[i - 1][j];
			else
				v[i][j] = max1(v[i-1][j], v[i - 1][j - w[i]] + p[i]);
		}

	printf("The table is:\n");
	for(i = 0; i <= n; i++){
		for(j = 0; j <= max; j++)
			printf("%d  ", v[i][j]);
			printf("\n");
	}
		
	printf("Maximum prorit : %d", v[n][max]);
	printf("\n");

	printf("Most valuable subset is:\n");
	j = max;

	for(i = n; i >= 1; i--)
		if(v[i][j] != v[i - 1][j])
    	{
	    	printf("Item %d :  ", i);
		    j = j - w[i];
		}
}