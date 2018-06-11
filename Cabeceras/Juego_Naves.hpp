#ifndef JUEGO_NAVES_HPP
#define JUEGO_NAVES_HPP

#include "Nave_Principal.hpp"
#include "Nave_Enemiga.hpp"

class Juego_Naves{
public:
    Juego_Naves(void){}
    Juego_Naves(int _vidas, int _cant_enemigos, int _x_enemiga, int _y_enemiga, int _x_principal, int _y_principal);
    ~Juego_Naves(){}

    //Métodos.
    void inicializar_juego(int _vidas, int _cant_enemigos, int _x_enemiga, int _y_enemiga, int x_p, int y_p);
    /*
    *Incializa los objetos para el juego.
    */
    void re_iniciar_juego();
    /*
    *Reinicia el juego.
    */
    void jugar(void);
    /*
    *Pone en marcha los algoritmos para que el juego funcione.
    */

private:
    Nave_Enemiga** _naves;
    Nave_Principal nave;
    int cant_enemigos;

    int x_enemiga;
    int y_enemiga;
    int x_principal;
    int y_principal;
    int vidas;

    char musica[30];
};

#include "../Codigo_Fuente/Juego_Naves.cpp"

#endif // JUEGO_NAVES_HPP
