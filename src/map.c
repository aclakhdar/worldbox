#include "main.h"

void chose_color(SDL_Renderer *ren, int i, int j)
{
	switch (sand_color[i][j])
	{
		case 0:
			SDL_SetRenderDrawColor(ren, SAND_COLOR1);
		break;
		case 1:
			SDL_SetRenderDrawColor(ren, SAND_COLOR2);
		case 2:
			SDL_SetRenderDrawColor(ren, SAND_COLOR3);
		break;
		case 3:
			SDL_SetRenderDrawColor(ren, SAND_COLOR4);
		break;
		case 4:
			SDL_SetRenderDrawColor(ren, SAND_COLOR5);
		break;
		case 5:
			SDL_SetRenderDrawColor(ren, SAND_COLOR6);
		break;
	default:
		break;
	}

}

void draw_grid(SDL_Renderer *ren)
{
    SDL_SetRenderDrawColor(ren, COLOR_GRAY);
    for (int x = 0; x <= WINDOW_WIDTH; x += CELL_SIZE) // vertical lines |
	{
        SDL_RenderDrawLine(ren, x, 0, x, WINDOW_HEIGHT);
    }

    for (int y = 0; y <= WINDOW_HEIGHT; y += CELL_SIZE) //horizontal line _
	{
        SDL_RenderDrawLine(ren, 0, y, WINDOW_WIDTH, y);
    }

	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			if (grid[i][j] == SAND)
			{
				chose_color(ren, i, j);
				SDL_Rect rect = {i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE};
				SDL_RenderFillRect(ren, &rect);
			}
			if (grid[i][j] == WATER)
			{
				SDL_SetRenderDrawColor(ren, WATER_COLOR1);
				SDL_Rect rect = {i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE};
				SDL_RenderFillRect(ren, &rect);
			}
		}
	}
}

void update_grid()
{
	for (int j = GRID_HEIGHT - 2; j >= 0; j--)
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			if (grid[i][j] == SAND)
				sand(i, j);
			else if(grid[i][j] == WATER)
				water(i, j);
		}
	}
}

void	clear_grid()
{
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			grid[i][j] = EMPTY;
			sand_color[i][j] = -1;
		}
	}
}
