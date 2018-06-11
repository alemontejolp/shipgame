#ifndef _NAVE_PRINCIPAL_HPP

#include "../Cabeceras/Naves.hpp"

class Nave_Principal : public Naves{
public:
    Nave_Principal(): Naves(){}
    Nave_Principal(int _vidas, int _x, int _y): Naves(_vidas, _x, _y) {_disparando = false; this->pintar_nave();}
    ~Nave_Principal(void){}

    //Métodos.
    void inicializar(int _vidas, int _x, int _y);
    /*
    *Hace la funcion de un constructor.
    */
    void disparar(void);
    /*
    *Usa la funcion disparando si se presiona la tecla
    *espacio.
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
    void destruir_nave(void)const;
    /*
    *Inicia la animación de destruccion de la
    *nave en cuestión.
    */
    void andando(void);
    /*
    *Junta todos los métodos de esta nave.
    */
    int revisar_estado_nave(Naves*); ///Nuevo. PASAR SU DIRECCION DE MEMORIA
    /*
    *Hace algo si la nave sufre cambios.
    *-Reduce vida si es golpeada.
    */

private:
    bool _disparando;
};

#include "../Codigo_Fuente/Nave_Principal.cpp"

#define _NAVE_PRINCIPAL_HPP
#endif // _NAVE_PRINCIPAL_HPP
