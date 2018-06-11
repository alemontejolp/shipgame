#ifndef NAVE_ENEMIGA_HPP
#define NAVE_ENEMIGA_HPP

#include "../Cabeceras/Naves.hpp"

class Nave_Enemiga : public Naves{
public:
    Nave_Enemiga(void){}
    Nave_Enemiga(int _vidas, int _x, int _y);
    ~Nave_Enemiga(void){}

    //Métodos.
    void inicializar(int, int, int);
    /*
    *Hace la funcion del constructor.
    */
    void mover(int, int);
    /*
    *Sobreescribe el método mover de la clase base.
    */
    void re_posicionar(void);
    /*
    *Cambia de pos a la nave.
    */
    int eleccion_aleatoria(void);
    /*
    *Genera una número entero al azar
    *para distintos propósitos. Del 1 al 10.
    */
    void disparar(void);
    /*
    *Decide si se dispara o no.
    */
    void disparando(void);
    /*
    *Ejecutará una animación en la que disára
    *asteriscos. xD
    */
    void pintar_nave(void)const;
    /*
    *Dibujará la nave en el lugar que indican
    *las coordenadas del objeto.
    */
    void borrar_nave(void)const;
    /*
    *Pintará espacios en lugar de astericos
    *para desaparecer la nave en las coordenadas
    *del objeto.
    */
    void destruir_nave(void);
    /*
    *Inicia la animación de destruccion de la
    *nave en cuestión.
    */
    void revisar_estado_nave(Naves*); ///Nuevo.
    /*
    *Hace algo si la nave sufre cambios.
    *-Reduce vida si es golpeada.
    */
    void andando(void);
    /*
    *Junta varios metodos para que la nave
    *interactue.
    */
    void movimiento(void);
    /*
    *Decide a que velocidad se mueve la nave.
    */
private:
    bool destruyendose;
    bool _disparando;
    int num_aleatorio;
    int fase_explosion;
};

#include "../Codigo_Fuente/Nave_Enemiga.cpp"

#endif // NAVE_ENEMIGA_HPP

