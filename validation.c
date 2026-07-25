#include "rush01.h"

int	check_left(int grid[4][4], int row, int expected)
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			visible++;
		}
		i++;
	}
	return (visible == expected);
}

int	check_right(int grid[4][4], int row, int expected)
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			visible++;
		}
		i--;
	}
	return (visible == expected);
}

int	check_up(int grid[4][4], int col, int expected)
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			visible++;
		}
		i++;
	}
	return (visible == expected);
}

int	check_down(int grid[4][4], int col, int expected)
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			visible++;
		}
		i--;
	}
	return (visible == expected);
}
