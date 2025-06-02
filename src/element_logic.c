#include "main.h"

void sand(int i, int j)
{
	if (grid[i][j + 1] == EMPTY || grid[i][j + 1] == WATER)
	{
		grid[i][j + 1] = SAND;
		if (grid[i][j + 1] == WATER)
			grid[i][j] = WATER;
		else
			grid[i][j] = EMPTY;
		sand_color[i][j + 1] = sand_color[i][j];
	}
	else
	{
   		int dir = rand() % 2; // 0 = left, 1 = right
		if (dir == 0 && i > 0 && grid[i - 1][j + 1] == EMPTY)
		{
			grid[i - 1][j + 1] = SAND;
			grid[i][j] = EMPTY;
			sand_color[i - 1][j + 1] = sand_color[i][j];
		} else if (dir == 1 && i < GRID_WIDTH - 1 && grid[i + 1][j + 1] == EMPTY)
		{
			grid[i + 1][j + 1] = SAND;
			grid[i][j] = EMPTY;
			sand_color[i + 1][j + 1] = sand_color[i][j];
		}
	}
}

void	water(int i, int j)
{
	if (grid[i][j + 1] == EMPTY)
	{
		grid[i][j + 1] = WATER;
		grid[i][j] = EMPTY;
	}
	else
	{
   		int dir = rand() % 2; // 0 = left, 1 = right
		if (dir == 0 && i > 0 && grid[i - 1][j + 1] == EMPTY)
		{
			grid[i - 1][j + 1] = WATER;
			grid[i][j] = EMPTY;
		} else if (dir == 1 && i < GRID_WIDTH - 1 && grid[i + 1][j + 1] == EMPTY)
		{
			grid[i + 1][j + 1] = WATER;
			grid[i][j] = EMPTY;
		}
		else
		{
			if (i > 0 && grid[i - 1][j] == EMPTY && dir == 0)
			{
				grid[i - 1][j] = WATER;
				grid[i][j] = EMPTY;
			}
			else if (i < GRID_WIDTH - 1 && grid[i + 1][j] == EMPTY)
			{
				grid[i + 1][j] = WATER;
				grid[i][j] = EMPTY;
			}
		}
	}
}
