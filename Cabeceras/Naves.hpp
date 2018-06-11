#ifndef _NAVES_HPP
#define _NAVES_HPP

enum ASCII {ESPACIO = 32, ARRIBA = 72, ABAJO = 80, IZQUIERDA = 75, DERECHA = 77,
            ESC = 27, RETORNO = 13, BORRAR = 8};

class Naves{
public:
    Naves(){}//Constructot por defecto.
    Naves(int _vidas, int x, int y): vidas(_vidas), x_delante(x), y_delante(y),
    x_medio(x - 1), y_medio(y + 1), x_cola(x - 2), y_cola(y + 2),  iteracion(0) {} //Constructor con posicionamiento de la nave.
    virtual ~Naves(){}

    //Datos públicos:
    static int kills;

    //Métodos mienbro.
    void re_posicionar(int x, int y);
    /*
    *Cambia de posicion a 'x' y a 'y'.
    */
    void mover(int x, int y);
    /*
    *Se le pasaran valores que se le sumaran a
    *'x' y a 'y'.
    */
    void detectar_movimiento(void);
    /*
    *Revisa si la tecla que se pulsó es una de las de direccion
    */
    bool detectar_choque(Naves*)const; // <---
    /*
    *Revisa si algún objeto ha colisionado con
    *las coordenadas de éste objetos.
    *En el main, va a hacer un ciclo pasando
    *cada posiion de un arreglo de naves como
    *punterios hacia naves enemigas para
    *detectar si alguna choca con la principal.
    */
    void decrementar_vida(void);
    /*
    *Disminuirá la vida del objeto en 1
    *cada vez de se imboque a este método.
    */
    bool detectar_disparo(Naves*); ///Nuevo, revisar.-
    /*
    *Vera si alguna bala está dentro de los límites
    *de la nave.
    */

protected:
    int vidas;
    int re_vidas;
    int x_delante;
    int y_delante;
    int x_medio;// de x1 a x2 hay 2 de espacio.
    int y_medio; //Se matiene en y.
    int x_cola;// de x1 a x2 hay 4 de espacio.
    int y_cola; //Se mantiene en y.

    int ant_x_delante;
    int ant_y_delante;
    int ant_x_medio;// de x1 a x2 hay 2 de espacio.
    int ant_y_medio; //Se matiene en y.
    int ant_x_cola;// de x1 a x2 hay 4 de espacio.
    int ant_y_cola; //Se mantiene en y.

    int x_disparo;
    int y_disparo;

    int tecla;
    int iteracion;

};

#include "../Codigo_Fuente/Naves.cpp"

#endif // _NAVES_HPP
