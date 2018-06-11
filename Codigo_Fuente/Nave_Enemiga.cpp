#include <conio.h>
#include <cstdlib>

Nave_Enemiga::Nave_Enemiga(int _vidas, int _x, int _y): Naves(){
    this->x_delante = _x;
    this->y_delante = _y;

    this->x_medio = _x - 1;
    this->y_medio = _y - 1;

    this->x_cola = _x - 2;
    this->y_cola = _y - 2;

    this->vidas = _vidas;
    this->re_vidas = _vidas;
    this->destruyendose = false;
    this->fase_explosion = 0;
    this->iteracion = 0;

    this->pintar_nave();
}

void Nave_Enemiga::inicializar(int _vidas, int _x, int _y){
    this->x_delante = _x;
    this->y_delante = _y;

    this->x_medio = _x - 1;
    this->y_medio = _y - 1;

    this->x_cola = _x - 2;
    this->y_cola = _y - 2;

    this->vidas = _vidas;
    this->re_vidas = _vidas;
    this->destruyendose = false;
    this->fase_explosion = 0;
    this->iteracion = 0;

    this->pintar_nave();

    this->_disparando = false;
    this->x_disparo = -1;
    this->y_disparo = -1;

    return;
}

void Nave_Enemiga::mover(int x, int y){
    this->x_delante += x;
    this->y_delante += y;
    this->x_medio = x_delante - 1;
    this->y_medio = y_delante - 1;
    this->x_cola = x_delante - 2;
    this->y_cola = y_delante - 2;

    return;
}

void Nave_Enemiga::re_posicionar(void){
    this->borrar_nave();

    this->y_delante = 4;
    this->x_delante = rand() % 101;

    if(this->x_delante < 3){
        this->x_delante += 3;
    }
    else if(this->x_delante > 97){
        this->x_delante -= 3;
    }
    /*
    this->x_delante = x_delante;
    this->y_delante = y_delante;*/

    this->x_medio = x_delante - 1;
    this->y_medio = y_delante - 1;

    this->x_cola = x_delante - 2;
    this->y_cola = y_delante - 2;

    return;
}

int Nave_Enemiga::eleccion_aleatoria(void){
    num_aleatorio = rand() % 11;
    return num_aleatorio;
}

void Nave_Enemiga::disparar(void){
    if((this->eleccion_aleatoria() >= 5) && (!_disparando)){
        this->_disparando = true;
        this->x_disparo =  this->x_delante;
        this->y_disparo = this->y_delante + 2;
        this->disparando();
    }
    ///
    /*gotoxy(4, 1);cout << num_aleatorio;///Borrar
    gotoxy(1, 1);cout << " ";///Borrar
    gotoxy(1, 1);cout << _disparando;///Borrar
    gotoxy(8, 1);cout << y_delante;///Borrar*/
    return;
}

void Nave_Enemiga::disparando(void){
    if(this->y_delante > 34){
        //gotoxy(x_disparo, y_disparo - 1);cout << " ";
        this->_disparando = false;
    }
    else if(this->_disparando && (this->iteracion % 800 == 0)){
        gotoxy(this->x_disparo, this->y_disparo - 1); cout << " ";
        gotoxy(this->x_disparo, this->y_disparo);cout << "|";
        this->y_disparo++;
        if(y_disparo >= 39){
            gotoxy(x_disparo, y_disparo - 1);cout << " ";
            this->_disparando = false;
            this->y_disparo = -1;
        }
    }
    return;
}

void Nave_Enemiga::pintar_nave(void)const{
    gotoxy(this->x_cola, this->y_cola);    cout << "vvvvv";
    gotoxy(this->x_medio, this->y_medio);   cout << "vvv";
    gotoxy(this->x_delante, this->y_delante);cout << "v";
    return;
}

void Nave_Enemiga::borrar_nave(void)const{
    gotoxy(this->ant_x_cola, this->ant_y_cola);    cout << "     ";
    gotoxy(this->ant_x_medio, this->ant_y_medio);   cout << "   ";
    gotoxy(this->ant_x_delante, this->ant_y_delante);cout << " ";
    return;
}

void Nave_Enemiga::destruir_nave(void){
    ///Usar en main.
    if(this->destruyendose){
        if(iteracion % 500 == 0 && fase_explosion == 1){///Que otro método dirija el comportamiento de las iteraciones.
            gotoxy(this->x_cola, this->y_cola);    cout << "v vvv v";
            gotoxy(this->x_medio, this->y_medio);   cout << "v v v";
            gotoxy(this->x_delante, this->y_delante); cout << "v";

            this->fase_explosion++;
        }
        else if(this->iteracion % 500 == 0 && this->fase_explosion == 2){
            gotoxy(this->x_cola, this->y_cola);    cout << "v v v v v";
            gotoxy(this->x_medio, this->y_medio);   cout << "v  v  v";
            gotoxy(this->x_delante, this->y_delante);  cout << "v";

            this->fase_explosion++;
        }
        else if(this->iteracion % 500 == 0 && this->fase_explosion == 3){
            gotoxy(this->x_cola, this->y_cola);    cout << "- / v \ -";
            gotoxy(this->x_medio, this->y_medio);   cout << "v  -  v";
            gotoxy(this->x_delante, this->y_delante);  cout << "v";

            this->fase_explosion++;
        }
        else if(this->iteracion % 500 == 0 && this->fase_explosion == 4){
            gotoxy(this->x_cola, this->y_cola);    cout << "-  - v -  -";
            gotoxy(this->x_medio, this->y_medio);    cout << "-  -  -";
            gotoxy(this->x_delante, this->y_delante);   cout << "*";

            this->fase_explosion++;
        }
        else if(this->iteracion % 500 == 0  && this->fase_explosion == 5){
            this->borrar_nave();
            this->iteracion = 0;
            this->fase_explosion = 0;
            this->destruyendose = false;
            this->vidas = re_vidas;
            kills++;

            gotoxy(1, 1);cout << "Kills:    ";
            gotoxy(1, 1);cout << "Kills: " << kills;

            this->re_posicionar();
        }

    }
    return;
}

void Nave_Enemiga::revisar_estado_nave(Naves* nave_p){

    if(this->detectar_choque(nave_p) || this->detectar_disparo(nave_p)){
        this->decrementar_vida();
        /*gotoxy(80, 1);cout << "Salud:       ";
        gotoxy(80, 1);cout << "Salud: " << this->vidas;*/

        /*gotoxy(1, 2);cout << "x_delante : " << this->x_delante;
        gotoxy(1, 3);cout << "y_delante : " << this->y_delante;
        gotoxy(1, 4);cout << "x_medio : " << this->x_medio;
        gotoxy(1, 5);cout << "y_medio : " << this->y_medio;
        gotoxy(1, 6);cout << "x_cola : " << this->x_cola;
        gotoxy(1, 7);cout << "y_cola : " << this->y_cola;

        gotoxy(17, 2);cout << "n_x_delante :" << nave_p->x_delante;
        gotoxy(17, 3);cout << "n_y_delante : " << nave_p->y_delante;
        gotoxy(17, 4);cout << "n_x_medio : " << nave_p->x_medio;
        gotoxy(17, 5);cout << "n_y_medio : " << nave_p->y_medio;
        gotoxy(17, 6);cout << "n_x_cola : " << nave_p->x_cola;
        gotoxy(17, 7);cout << "n_y_cola : " << nave_p->y_cola;
        getch();*/

    }

    if(vidas <= 0 && (!destruyendose)){
        this->destruyendose = true;
        this->fase_explosion = 1;
    }

    if(this->destruyendose){
        this->destruir_nave();
    }
}

void Nave_Enemiga::movimiento(void){
    /*if(this->y_delante >= 39){
        this->re_posicionar();
        this->borrar_nave();
        this->pintar_nave();
    }*/
    if(iteracion % 1500 == 0){
        this->ant_x_delante = this->x_delante;
        this->ant_y_delante = this->y_delante;
        this->ant_x_medio = this->x_medio;// de x1 a x2 hay 2 de espacio.
        this->ant_y_medio = this->y_medio; //Se matiene en y.
        this->ant_x_cola = this->x_cola;// de x1 a x2 hay 4 de espacio.
        this->ant_y_cola = this->y_cola; //Se mantiene en y.

        if(this->y_delante < 39){ //gotoxy(20, 1);cout << "Ejecuta Mov";getch();gotoxy(20, 1); cout << "           ";
            this->mover(0, 1);
            this->borrar_nave();
            this->pintar_nave();
        }
        else{
            this->re_posicionar();
        }
    }
    return;
}

void Nave_Enemiga::andando(void){
    this->movimiento();
    this->disparar();

    this->iteracion++; //gotoxy(12, 1);cout << iteracion;

    return;
}
