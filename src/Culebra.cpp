#include <cstdlib>
#include <ctime>
#include "Culebra.h"
#include "Constantes.h"

Culebra::Culebra()
{
    srand(time(NULL));

    Culebra::posicionActual.x = TAM_CULEBRA*TAM_CUADRO;
    Culebra::posicionActual.y = TAM_CULEBRA*TAM_CUADRO;

    Culebra::cuerpo = new List<SDL_Point>();
    Culebra::direccion = 3;

    SDL_Point p = Culebra::posicionActual;
    Culebra::cuerpo->append(p);

    p = Culebra::posicionActual;
    Culebra::cuerpo->append(p);

    p = Culebra::posicionActual;
    Culebra::cuerpo->append(p);

    p = Culebra::posicionActual;
    Culebra::cuerpo->append(p);

    p = Culebra::posicionActual;
    Culebra::cuerpo->append(p);

    Culebra::asignarPunto();
}

SDL_Point Culebra::getPosicionActual()
{
    return Culebra::posicionActual;
}

SDL_Point Culebra::getPuntoSiguiente()
{
    return Culebra::puntoSiguiente;
}

List<SDL_Point>* Culebra::getCuerpo()
{
    return Culebra::cuerpo;
}

int Culebra::getDireccion()
{
    return Culebra::direccion;
}

void Culebra::setPosicionActual(SDL_Point x)
{
    Culebra::posicionActual = x;
}

void Culebra::setPuntoSiguiente(SDL_Point y)
{
    Culebra::puntoSiguiente = y;
}

void Culebra::setDireccion(int x)
{
    Culebra::direccion = x;
}

bool Culebra::puedeComer()
{
    SDL_Point p;
    p.x = Culebra::posicionActual.x;
    p.y = Culebra::posicionActual.y;

    //cout << "{" << p.x << " " << p.y << " , " << Culebra::puntoSiguiente.x << " "<< Culebra::puntoSiguiente.y << "}" << endl;

    if (p.x == Culebra::puntoSiguiente.x &&
        p.y == Culebra::puntoSiguiente.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Culebra::comer()
{
    SDL_Point p;
    p.x = Culebra::puntoSiguiente.x;
    p.y = Culebra::puntoSiguiente.y;

    Culebra::cuerpo->pushBack(p);

    Culebra::asignarPunto();
}

bool Culebra::mover()
{
    if (Culebra::puedeComer())
    {
        Culebra::comer();
    }
    else
    {
        Culebra::cuerpo->popFront();
        Culebra::cuerpo->pushBack(posicionActual);
    }

    if (Culebra::direccion == 0)
    {
        SDL_Point p = Culebra::posicionActual;

        Culebra::posicionActual.x = p.x;
        Culebra::posicionActual.y = p.y + TAM_CULEBRA;
    }
    else if (Culebra::direccion == 1)
    {
        SDL_Point p = Culebra::posicionActual;

        Culebra::posicionActual.x = p.x;
        Culebra::posicionActual.y = p.y - TAM_CULEBRA;
    }
    else if (Culebra::direccion == 2)
    {
        SDL_Point p = Culebra::posicionActual;

        Culebra::posicionActual.x = p.x - TAM_CULEBRA;
        Culebra::posicionActual.y = p.y;
    }
    else
    {
        SDL_Point p = Culebra::posicionActual;

        Culebra::posicionActual.x = p.x + TAM_CULEBRA;
        Culebra::posicionActual.y = p.y;
    }

    //cout << Culebra::posicionActual.x << "," << Culebra::posicionActual.y << endl;
    //cout.flush();

    if (Culebra::posicionActual.x >= TAM_VENTANA_X || Culebra::posicionActual.x < 0 ||
        Culebra::posicionActual.y >= TAM_VENTANA_Y || Culebra::posicionActual.y < 0)
    {
        return false;
    }

    //Buscamos si no nos mordimos
    for (unsigned i = 0; i < Culebra::cuerpo->getSize(); i++)
    {
        SDL_Point p1 = Culebra::cuerpo->recover(i);

        if ((p1.x == Culebra::posicionActual.x) &&
            (p1.y == Culebra::posicionActual.y))
        {
            return false;
        }
    }

    return true;
}

void Culebra::asignarPunto()
{
    SDL_Point p;
    bool valido = false;

    while (! valido)
    {
        valido = true;

        p.x = (TAM_CULEBRA * (rand()%TAM_CUADRO*TAM_CUADRO)) % TAM_VENTANA_X;
        p.y = (TAM_CULEBRA * (rand()%TAM_CUADRO*TAM_CUADRO)) % TAM_VENTANA_Y;

        for (unsigned i = 0; i < Culebra::cuerpo->getSize(); i++)
        {
            SDL_Point p1 = Culebra::cuerpo->recover(i);

            if ((p1.x == p.x) &&
                (p1.y == p.y))
            {
                valido = false;
            }
        }
    }

    Culebra::puntoSiguiente.x = p.x;
    Culebra::puntoSiguiente.y = p.y;
}
