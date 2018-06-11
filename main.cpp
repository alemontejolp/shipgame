#include "Cabeceras/Juego_Naves.hpp"

int Naves::kills = 0;

int main(){
    Juego_Naves juego;

    juego.inicializar_juego(100, 3, 5, 7, 45, 10);

    juego.jugar();

    return 0;
}
