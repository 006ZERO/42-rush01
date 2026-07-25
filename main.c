#include "rush01.h"

void	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	parse_input(char *str, int clues[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (count >= 16)
				return (0);
			clues[count++] = str[i] - '0';
		}
		else if (str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (count == 16);
}

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];

	if (argc != 2 || !parse_input(argv[1], clues))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_grid(grid);
	if (solve(grid, clues, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
