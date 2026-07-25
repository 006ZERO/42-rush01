#include "rush01.h"

int	is_valid(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_line_constraints(int grid[4][4], int clues[16], int row, int col)
{
	if (col == 3)
	{
		if (!check_left(grid, row, clues[8 + row]))
			return (0);
		if (!check_right(grid, row, clues[12 + row]))
			return (0);
	}
	if (row == 3)
	{
		if (!check_up(grid, col, clues[col]))
			return (0);
		if (!check_down(grid, col, clues[4 + col]))
			return (0);
	}
	return (1);
}

int	solve(int grid[4][4], int clues[16], int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (1);
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (check_line_constraints(grid, clues, row, col))
			{
				if (solve(grid, clues, pos + 1))
					return (1);
			}
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
