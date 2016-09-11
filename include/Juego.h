#ifndef JUEGO_H
#define JUEGO_H

#include "Constantes.h"
#include "Culebra.h"

class Juego
{
    private:
        SDL_Window* ventana;
        SDL_Renderer* ren;
        Culebra culebra;

    public:
        Juego();
        Juego(SDL_Window* w, SDL_Renderer* r);
        void jugar();
        void dibujar();

};

#endif // JUEGO_H
