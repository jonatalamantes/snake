#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include "Constantes.h"
#include "Juego.h"

using namespace std;

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_JPG);
	TTF_Init();

	SDL_Window * window = SDL_CreateWindow("Laberinto",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            TAM_VENTANA_X,
                                            TAM_VENTANA_Y,
                                            SDL_WINDOW_SHOWN);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	Juego j(window, renderer);
	j.jugar();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
