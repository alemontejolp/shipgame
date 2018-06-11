#include "windows.h"
#include "iostream"
//Funciones que podria usar despues.

//Prototipos.
void gotoxy (int, int);
void tabla (int, int, int, int, int, int);
bool ajustar_ventana(int, int);

//Definiciones.
void gotoxy(int x, int y) {
    HANDLE consola;
    consola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordenadas;
    coordenadas.X = x;
    coordenadas.Y = y;
    SetConsoleCursorPosition(consola, coordenadas);
}
void tabla (int x, int y, int filas, int columnas, int alto, int ancho) {
    //filas = ((filas * 2) +1);
    ancho = (ancho + 2);
    //columnas = ()
    int incDeAlto = (alto + 1); //Incremento de alto.
    alto = (alto + 2);
    int contF = 0; //Contador de Filas.
    int contAn = 0; //Contador de Ancho.
    int contAlt = 0; //Contador de alto.
    int contC = 0; //Contador de Columnas.
    int limiteContAlt = incDeAlto;
    int limiteAncho = ancho;
    limiteAncho -=1;

    for (contF = 0; contF < filas; contF++) {
        for (contC = 0; contC < columnas; contC++) {
            for (contAlt = 0; contAlt < alto; contAlt++) {
                for (contAn = 0; contAn < ancho; contAn++) {
                    if ((contAlt != limiteContAlt) && (contAn == 0 || contAn == limiteAncho)) {
                        gotoxy(x,y);std::cout << "*";
                    }
                    else if (contAlt == limiteContAlt || contAlt == 0){
                        gotoxy(x,y);std::cout << "*";
                    }
                    x++;

                } //Aqui caba el ancho.
                x-=(ancho);
                y++;
                if (contAlt == limiteContAlt) {
                    limiteContAlt += incDeAlto;
                }
            } //Aqui termina el Alto. ---Esto crea un cuadro.
            y-= alto;
            x += (ancho-1); //Antes estaba "ancho"
            limiteContAlt = incDeAlto;
        } //Aqui acaba las columnas. ---Esto indica cuantos cuadros a la derecha.
        y+= (alto-1); //Antes estaba "alto"
        x = (x - ((ancho-1) * columnas));
    } //Aqui acaban las filas. ---Esto indica cuantos cuadros hacia abajo.
} // Aqui acaba la funcion.

bool ajustar_ventana(int ancho, int alto){
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE); //Consigue el HANDLE de la consola.

    COORD coordenadas; //Da las coordenadas de la consola.
    coordenadas.X = ancho;
    coordenadas.Y = alto;

    _SMALL_RECT rect; //Da los tamaños a la consola.
    rect.Top = 0;
    rect.Left = 0;
    rect.Right = ancho - 1;
    rect.Bottom = alto - 1;

    SetConsoleScreenBufferSize(consola, coordenadas); //Ajusta el buffer al nuevo tamaño.

    SetConsoleWindowInfo(consola, true, &rect); //Cambia el tamaño de la consola a lo espesificado en el buffer.
    return true;
}
