#include "Juego.h"

Juego::Juego()
{
    Juego::ventana = NULL;
    Juego::ren = NULL;
}

Juego::Juego(SDL_Window* w, SDL_Renderer* r)
{
    Juego::ventana = w;
    Juego::ren = r;
}

void Juego::dibujar()
{
    //Ponemos la pantalla
    SDL_SetRenderDrawColor(Juego::ren, 0, 0, 0, 255);
    SDL_RenderClear(Juego::ren);

    for (unsigned int i = 0; i < Juego::culebra.getCuerpo()->getSize(); i++)
    {
        SDL_Point p = Juego::culebra.getCuerpo()->recover(i);

        SDL_Rect r;
        r.w = TAM_CULEBRA;
        r.h = TAM_CULEBRA;
        r.x = p.x;
        r.y = p.y;

        if (i == 0)
        {
            SDL_SetRenderDrawColor(Juego::ren, 150, 0, 0, 255);
        }
        else if (i == Juego::culebra.getCuerpo()->getSize() -1)
        {
            SDL_SetRenderDrawColor(Juego::ren, 0, 150, 0, 255);
        }
        else
        {
            SDL_SetRenderDrawColor(Juego::ren, 150, 150, 150, 255);
        }

        SDL_RenderFillRect(Juego::ren, &r);

        SDL_SetRenderDrawColor(Juego::ren, 255, 255, 255, 255);
        SDL_RenderDrawRect(Juego::ren, &r);

        r.w = TAM_CULEBRA;
        r.h = TAM_CULEBRA;
        r.x = Juego::culebra.getPuntoSiguiente().x;
        r.y = Juego::culebra.getPuntoSiguiente().y;

        SDL_SetRenderDrawColor(Juego::ren, 255, 150, 150, 255);
        SDL_RenderDrawRect(Juego::ren, &r);

        //cout << r.w << " " << r.h << " " << r.x << " " << r.y << " " << endl;

        /*r.w = TAM_CULEBRA;
        r.h = TAM_CULEBRA;
        r.x = Juego::culebra.getPosicionActual().x;
        r.y = Juego::culebra.getPosicionActual().y;

        SDL_SetRenderDrawColor(Juego::ren, 0, 0, 255, 255);
        SDL_RenderDrawRect(Juego::ren, &r);*/
    }

    SDL_RenderPresent(Juego::ren);
}

void Juego::jugar()
{
    bool quit = false;
	SDL_Event event;

	double tiempo = SDL_GetTicks();

    while (!quit)
	{
	    dibujar();

	    if (SDL_GetTicks() > tiempo + 40)
        {
            tiempo = SDL_GetTicks();

            if (! Juego::culebra.mover())
            {
                dibujar();
                cout << "GAME OVER";
                SDL_Delay(1000);
                quit = true;
            }
        }

		if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                cout << "GAME OVER";
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_q)
                {
                    quit = true;
                }
                else if (event.key.keysym.sym == SDLK_UP)
                {
                    if (Juego::culebra.getDireccion() != 0)
                    {
                        Juego::culebra.setDireccion(1);
                    }
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    if (Juego::culebra.getDireccion() != 1)
                    {
                        Juego::culebra.setDireccion(0);
                    }
                }
                else if (event.key.keysym.sym == SDLK_LEFT)
                {
                    if (Juego::culebra.getDireccion() != 3)
                    {
                        Juego::culebra.setDireccion(2);
                    }
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    if (Juego::culebra.getDireccion() != 2)
                    {
                        Juego::culebra.setDireccion(3);
                    }
                }
            }
        }
	}

}
