#include "main.h"

int grid[GRID_WIDTH][GRID_HEIGHT];
int sand_color[GRID_WIDTH][GRID_HEIGHT];

void init(t_window *window, t_pos *pos)
{
	SDL_Window *win = NULL;
	SDL_Renderer *ren = NULL;
	SDL_Event event;
	int running = 1;
	window->mouse_down = 0;
	window->radius = 5;
	window->type = SAND; //default type

	pos->x = 100;
	pos->y = 100;

	for (int i = 0 ; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			grid[i][j] = 0;
		}
	}
}


int main(int ac, char **av)
{
	t_window window;
	t_pos pos; //no use for now
	init(&window, &pos);
	SDL_Init(SDL_INIT_VIDEO);
	window.win = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	window.ren = SDL_CreateRenderer(window.win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	while (window.running)
	{
		Uint32 frame_start = SDL_GetTicks();

		while (SDL_PollEvent(&window.event))
			event_handler(&window, &pos);

		update_mouse_position(&window);
		SDL_SetRenderDrawColor(window.ren, COLOR_BLACK);
		SDL_RenderClear(window.ren);
		update_grid(window.ren);
		draw_grid(window.ren);
		update_cursor(&window);
		SDL_RenderPresent(window.ren);

		Uint32 frame_time = SDL_GetTicks() - frame_start;
		if (frame_time < FRAME_DELAY)
			SDL_Delay(FRAME_DELAY - frame_time);
	}

	SDL_DestroyRenderer(window.ren);
	SDL_DestroyWindow(window.win);
	SDL_Quit();
}
