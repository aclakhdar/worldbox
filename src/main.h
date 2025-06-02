#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>

//game constants
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "ALPHA TEST"
#define FPS 60
#define FRAME_DELAY (1000 / FPS)
#define CELL_SIZE 7
#define GRID_WIDTH  (WINDOW_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_SIZE)
#define MOVE_SPEED 10 // removeble ig
#define RADIUS_MAX 50
#define RADIUS_MIN 5

//colores
#define COLOR_RED 255, 0, 0, 255
#define COLOR_GREEN 0, 255, 0, 255
#define COLOR_BLUE 0, 0, 255, 255
#define COLOR_WHITE 255, 255, 255, 255
#define COLOR_BLACK 0, 0, 0, 255
#define COLOR_GRAY 50, 50, 50, 255

	#define SAND_COLOR1 179, 149, 58, 255
	#define SAND_COLOR2 191, 176, 131, 255
	#define SAND_COLOR3 186, 164, 99, 255
	#define SAND_COLOR4	198, 191, 168, 255
	#define SAND_COLOR5 193, 179, 138, 255
	#define SAND_COLOR6 186, 190, 166, 255

	#define WATER_COLOR1 0, 33, 243, 50
//element types
#define EMPTY 0
#define SAND 1
#define WATER 2
#define FIRE 3
#define STONE 4
#define PLANT 5

typedef struct s_window {
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event 		event;
	int				mouse_down;
	int				running;
	int				radius;
	int 			type;
} 					t_window;

typedef struct s_player {
	SDL_Texture *texture;
	SDL_Rect rect;
	int x;
	int y;
} t_player;

typedef struct s_pos
{
	int x;
	int y;
} t_pos;

extern int grid[GRID_WIDTH][GRID_HEIGHT];
extern int sand_color[GRID_WIDTH][GRID_HEIGHT];
extern int water_color[GRID_WIDTH][GRID_HEIGHT];

//event_handling.c
void 	event_handler(t_window *window, t_pos *pos);
void	update_mouse_position(t_window *window);
void	update_cursor(t_window *window);

//map.c
void	clear_grid();
void 	draw_grid(SDL_Renderer *ren);
void 	update_grid();

//element_logic.c
void	sand(int i, int j);
void	water(int i, int j);


#endif
