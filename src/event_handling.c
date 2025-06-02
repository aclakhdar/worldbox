#include "main.h"

void	update_mouse_position(t_window *window)
{
	if (window->mouse_down)
	{
		int mouse_x = 0, mouse_y = 0;
		SDL_GetMouseState(&mouse_x, &mouse_y);
		int cx = mouse_x / CELL_SIZE;
		int cy = mouse_y / CELL_SIZE;

		for (int y = -window->radius; y <= window->radius; y++)
		{
			for (int x = -window->radius; x <= window->radius; x++)
			{
				int grid_x = cx + x;
				int grid_y = cy + y;

				if (grid_x >= 0 && grid_x < GRID_WIDTH &&
					grid_y >= 0 && grid_y < GRID_HEIGHT &&
					(x * x + y * y) <= window->radius)
				{
					grid[grid_x][grid_y] = window->type;
					sand_color[grid_x][grid_y] = rand() % 6;
				}
			}
		}
	}
}

void event_handler(t_window *window, t_pos *pos)
{
	if (window->event.type == SDL_QUIT || (window->event.type == SDL_KEYDOWN && window->event.key.keysym.sym == SDLK_ESCAPE))
		window->running = 0;
	if (window->event.type == SDL_MOUSEBUTTONDOWN)
	{
		window->mouse_down = 1;
	}
	if (window->event.type == SDL_MOUSEBUTTONUP)
	{
		window->mouse_down = 0;
	}
	if (window->event.type == SDL_MOUSEWHEEL)
	{
		if (window->event.wheel.y > 0 && window->radius < RADIUS_MAX)
			window->radius += 4;
		if (window->event.wheel.y < 0 && window->radius > RADIUS_MIN)
			window->radius -= 4;
	}
	if (window->event.type == SDL_KEYDOWN)
	{
		if (window->event.key.keysym.sym == SDLK_c)
			clear_grid();
		if (window->event.key.keysym.sym == SDLK_1)
			window->type = SAND;
		if (window->event.key.keysym.sym == SDLK_2)
			window->type = WATER;
	// 	if (window->event.key.keysym.sym == SDLK_s)
	// 		pos->y += MOVE_SPEED;
	}
}

void update_cursor(t_window *window)
{
	int mouse_x = 0, mouse_y = 0;
	SDL_GetMouseState(&mouse_x, &mouse_y);
	circleRGBA(window->ren, mouse_x, mouse_y, window->radius, COLOR_WHITE);
}
