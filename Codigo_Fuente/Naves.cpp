#ifndef NAVES_CPP

#include <conio.h>

void Naves::re_posicionar(int _x, int _y){
    this->x_delante = _x;
    this->y_delante = _y;

    this->x_medio = _x - 1;
    this->y_medio = _y + 1;

    this->x_cola = _x - 2;
    this->y_cola = _y + 2;

    return;
}

void Naves::mover(int x, int y){
    this->x_delante += x;
    this->y_delante += y;
    this->x_medio = x_delante - 1;
    this->y_medio = y_delante + 1;
    this->x_cola = x_delante - 2;
    this->y_cola = y_delante + 2;


    return;
}

void Naves::detectar_movimiento(void){
    if(tecla == ARRIBA|| tecla == ABAJO || tecla == DERECHA || tecla == IZQUIERDA){
        ant_x_delante = x_delante;
        ant_y_delante = y_delante;
        ant_x_medio = x_medio;// de x1 a x2 hay 2 de espacio.
        ant_y_medio = y_medio; //Se matiene en y.
        ant_x_cola = x_cola;// de x1 a x2 hay 4 de espacio.
        ant_y_cola = y_cola; //Se mantiene en y.
    }

    switch(tecla){
    case(ARRIBA):
        if(this->y_delante > 1)
            this->mover(0, -1);
        break;
    case(ABAJO):
        if(this->y_delante < 37)
            this->mover(0, 1);
        break;
    case(IZQUIERDA):
        if(this->x_delante > 3)
            this->mover(-1, 0);
        break;
    case(DERECHA):
        if(this->x_delante < 97)
            this->mover(1, 0);
        break;
    }
    return;
}

bool Naves::detectar_choque(Naves* nave)const{
    if( (this->x_delante == nave->x_delante) && nave->y_delante == this->y_delante){
        return true;
    }
    else if( ( (this->x_medio <= nave->x_delante) && (nave->x_delante <= this->x_delante + 1) ) && nave->y_delante == this->y_medio){
        return true;
    }
    else if( ( (this->x_cola <= nave->x_delante) && (nave->x_delante <= this->x_delante + 2) ) && nave->y_delante == this->y_cola){
        return true;
    }

    if( ( (this->x_cola <= nave->x_cola) && (nave->x_cola <= this->x_delante + 2) ) && nave->y_cola == this->y_cola){
        return true;
    }
    else if( ( (this->x_cola <= nave->x_delante + 2) && (nave->x_delante + 2 <= this->x_cola) ) && nave->y_cola + 2 == this->y_cola){
        return true;
    }
    /*if((this->y_cola >= nave->y_delante && this->y_delante <= nave->y_delante) && (this->x_cola <= nave->x_delante && this->x_delante + 2 >= nave->x_delante)){
        return true;
    }
    else if((this->y_cola >= nave->y_cola && this->y_delante <= nave->y_cola) && (this->x_cola <= nave->x_cola&& this->x_delante + 2 >= nave->x_cola)){
        return true;
    }
    else if((this->y_cola >= nave->y_cola && this->y_delante <= nave->y_cola) && (this->x_cola <= nave->x_delante + 2 && this->x_delante + 2 >= nave->x_delante + 2)){
        return true;
    }*/

    return false;
}

void Naves::decrementar_vida(void){
    this->vidas--;
    return;
}

bool Naves::detectar_disparo(Naves* nave){
    if(this->x_delante == nave->x_disparo && this->y_delante == nave->y_disparo){
        return true;
    }
    else if( ( (this->x_medio <= nave->x_disparo) && (nave->x_disparo <= this->x_delante + 1) ) && this->y_medio == nave->y_disparo ){
        return true;
    }
    else if ( ( (this->x_cola <= nave->x_disparo) && (nave->x_disparo <= this->x_delante + 2) ) && this->y_cola == nave->y_disparo ){
        return true;
    }

    return false;
}

#define NAVES_CPP
#endif // NAVES_CPP
