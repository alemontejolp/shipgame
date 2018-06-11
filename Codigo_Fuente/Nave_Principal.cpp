#include <conio.h>
#include "../Cabeceras/funciones.hpp"

using namespace std;

void Nave_Principal::inicializar(int _vidas, int _x, int _y){
    this->x_delante = _x;
    this->y_delante = _y;

    this->x_medio = _x - 1;
    this->y_medio = _y + 1;

    this->x_cola = _x - 2;
    this->y_cola = _y + 2;

    this->iteracion = 0;
    this->vidas = _vidas;

    this->pintar_nave();

    this->_disparando = false;

    this->x_disparo = -1;
    this->y_disparo = -1;

    return;
}

void Nave_Principal::disparar(void){
    if(tecla == ESPACIO && (!_disparando)){
        _disparando = true;
        x_disparo =  x_delante;
        y_disparo = y_delante - 2;
        this->disparando();
    }
    return;
}

void Nave_Principal::disparando(void){
    if(_disparando && (iteracion % 500 == 0)){
        gotoxy(x_disparo, y_disparo + 1); cout << " ";
        gotoxy(x_disparo, y_disparo);cout << "|";
        y_disparo--;
        if(y_disparo < 2){
            gotoxy(x_disparo, y_disparo + 1);cout << " ";
            this->_disparando = false;
            this->iteracion = 0;
            this->y_disparo = -1;
        }
    }
    iteracion++;
    return;
}

void Nave_Principal::pintar_nave(void)const{
    gotoxy(x_delante, y_delante);cout << "*";
    gotoxy(x_medio, y_medio);   cout << "***";
    gotoxy(x_cola, y_cola);    cout << "*****";

    return;
}

void Nave_Principal::borrar_nave(void)const{
    if(tecla == ARRIBA || tecla == ABAJO || tecla == DERECHA || tecla == IZQUIERDA){
        gotoxy(ant_x_delante, ant_y_delante);cout << " ";
        gotoxy(ant_x_medio, ant_y_medio);   cout << "   ";
        gotoxy(ant_x_cola, ant_y_cola);    cout << "     ";

        this->pintar_nave();
    }
    return;
}

void Nave_Principal::destruir_nave(void)const{
    Sleep(500);
    gotoxy(x_delante, y_delante); cout << "*";
    gotoxy(x_medio, y_medio);   cout << "* * *";
    gotoxy(x_cola, y_cola);    cout << "** * **";

    Sleep(500);
    gotoxy(x_delante, y_delante); cout << " *";
    gotoxy(x_medio, y_medio);   cout << " -* * x";
    gotoxy(x_cola, y_cola);    cout << "| *  - * |";

    Sleep(500);
    gotoxy(x_delante, y_delante); cout << "|";
    gotoxy(x_medio, y_medio);   cout << "- | -";
    gotoxy(x_cola, y_cola);    cout << "-.|/-*.´´";

    Sleep(500);
    system("cls");
    return;
}

void Nave_Principal::andando(void){
    if(kbhit()){
        tecla = getch();
        this->detectar_movimiento();
        this->disparar();
        this->borrar_nave();
    }
    return;
}

// Listo alv. xD Esta si se tendrá que usar desde main. xD
int Nave_Principal::revisar_estado_nave(Naves* nave){

    if(this->detectar_choque(nave) || this->detectar_disparo(nave)){
        this->decrementar_vida();
        /*gotoxy(1,1);cout << "Salud:           ";
        gotoxy(1,1);cout << "Salud: " << this->vidas;*/
    }

    if(vidas <= 0){

        this->destruir_nave();

    }

    return this->vidas;
}
