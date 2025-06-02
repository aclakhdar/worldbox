#include "main.h"

int grid[GRID_WIDTH][GRID_HEIGHT];
int sand_color[GRID_WIDTH][GRID_HEIGHT];

void init(t_window *window, t_pos *pos)
{
	SDL_Window *win = NULL;
	SDL_Renderer *ren = NULL;
	SDL_Event event;
	window->running = 1;
	window->mouse_down = 0;
	window->radius = 5;
	window->type = SAND; //default type
	window->font = TTF_OpenFont("asset/Pixeled.ttf", 24);
	window->textSurface = NULL;
	window->textTexture = NULL;


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


void	put_string(t_window *window)
{
	SDL_Color color = {255, 255, 255, 255};
	char *str;
	if (window->type == SAND)
		str = "Sand";
	else if (window->type == WATER)
		str = "Water";

	if (window->textSurface)
		SDL_FreeSurface(window->textSurface);
	if (window->textTexture)
		SDL_DestroyTexture(window->textTexture);

	strcpy(window->current_text, str);
	SDL_Surface *textSurface = TTF_RenderText_Blended(window->font, window->current_text, color);
	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(window->ren, textSurface);

	SDL_Rect textRect = {(WINDOW_WIDTH - textSurface->w) / 2, 100, textSurface->w, textSurface->h};
	SDL_RenderCopy(window->ren, textTexture, NULL, &textRect);
	if (window->textSurface)
		SDL_FreeSurface(window->textSurface);
	if (window->textTexture)
		SDL_DestroyTexture(window->textTexture);
}

int main(int ac, char **av)
{
	t_window window;
	t_pos pos; //no use for now
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	init(&window, &pos);
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
		put_string(&window);
		SDL_RenderPresent(window.ren);

		Uint32 frame_time = SDL_GetTicks() - frame_start;
		if (frame_time < FRAME_DELAY)
			SDL_Delay(FRAME_DELAY - frame_time);
	}
	SDL_DestroyRenderer(window.ren);
	SDL_DestroyWindow(window.win);
	SDL_Quit();
}
