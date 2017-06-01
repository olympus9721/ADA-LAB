#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int board[5], count;

int place(int row, int column)
{
	int i;
	for(i = 1; i <= row - 1; i++)
	{
		if(board[i] == column)
			return 0;
		else
			if(abs(board[i] - column) == abs(i - row))
				return 0;
	}
	return 1;
}

void display(int limit)
{
	int m, n;
	printf("Possible solution: %d \n",++count);
	for(m = 1; m <= limit; m++)
		printf("\t[%d]",m);
	for(m = 1; m <= limit; m++)
	{
		printf("\n\n[%d]", m);
		for(n = 1; n <= limit; n++)
		{
			if(board[m] == n)
				printf("\tQ");
			else
				printf("\t*");
		}
	}
	printf("\n");

}

void queen(int row, int limit)
{
	int column;
	for(column = 1; column <= limit; column++)
	{
		if(place(row, column))
		{
			board[row] = column;
		if(row == limit)
			display(limit);
		else
			queen(row + 1, limit);
		}
	}
}

void main()
{
	int n;
	printf("Enter the number of queens:\n");
	scanf("%d", &n);
	queen(1, n);
	printf("\n");
}