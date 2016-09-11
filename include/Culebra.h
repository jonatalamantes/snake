#ifndef CULEBRA_H
#define CULEBRA_H

#include <SDL2/SDL.h>
#include "List.h"

class Culebra
{
    private:
        SDL_Point posicionActual;
        SDL_Point puntoSiguiente;

        int direccion; //0 abajo, 1 arriba, 2 izquierda, 3 derecha

        List<SDL_Point>* cuerpo; //true desactiva, false activa

    public:
        Culebra();

        SDL_Point getPosicionActual();
        SDL_Point getPuntoSiguiente();
        int getDireccion();
        List<SDL_Point>* getCuerpo();

        void setPosicionActual(SDL_Point x);
        void setPuntoSiguiente(SDL_Point y);
        void setDireccion(int x);

        bool puedeComer();
        void comer();
        bool mover();
        void asignarPunto();
};

#endif // CULEBRA_H
