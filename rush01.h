#nfdef RUSH01_H
#define RUSH01_H

#include <unistd.h>

int		solve(int grid[4][4], int clues[16], int pos);
int		check_left(int grid[4][4], int row, int expected);
int		check_right(int grid[4][4], int row, int expected);
int		check_up(int grid[4][4], int col, int expected);
int		check_down(int grid[4E[4], int col, int expected);
int		is_valid(int grid[4E[4], int row, int col, int num);

#endif
