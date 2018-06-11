/*
*Codigo fuente para el juego. PD: Sólo quería rellenar este espacio alv. xdxd
*/
Juego_Naves::Juego_Naves(int _vidas, int _cant_enemigos, int _x_enemiga, int _y_enemiga, int _x_principal, int _y_principal){
    system("mode con cols=100 lines=40");
    system("title Juego de Naves");

    /*
    //Volver a activar cuando se tenga una música de fondo.
    char audio[] = "Recursos/Banda_Sonora.wav";
    strcpy(musica, audio);

    PlaySound((LPCSTR)musica, NULL, SND_FILENAME | SND_ASYNC);
    */

    this->x_enemiga = _x_enemiga;
    this->y_enemiga = _y_enemiga;

    this->x_principal = _x_principal;
    this->y_principal = _y_principal;

    this->vidas = _vidas;

    this->nave.inicializar(this->vidas, this->x_principal, this->y_principal);

    if(_cant_enemigos < 0){
        _cant_enemigos = 1;
    }
    else if(_cant_enemigos > 6) {
        _cant_enemigos = 6;

    }
    this->cant_enemigos = _cant_enemigos;

    this->_naves = new Nave_Enemiga* [this->cant_enemigos];

    for(int i = 0; i < this->cant_enemigos; i++){
        _naves[i] = new Nave_Enemiga(_vidas, _x_enemiga, _y_enemiga);

        _x_enemiga+= 25;
        _y_enemiga+= 5;
    }

    return;
}

void Juego_Naves::inicializar_juego(int _vidas, int _cant_enemigos, int _x_enemiga, int _y_enemiga, int _x_principal, int _y_principal){
    system("mode con cols=100 lines=40");
    system("title Juego de Naves");

    /*
    //Volver a activar cuando se tenga una música de fondo.
    char audio[] = "Recursos/Banda_Sonora.wav";
    strcpy(musica, audio);

    PlaySound((LPCSTR)musica, NULL, SND_FILENAME | SND_ASYNC);
    */

    this->x_enemiga = _x_enemiga;
    this->y_enemiga = _y_enemiga;

    this->x_principal = _x_principal;
    this->y_principal = _y_principal;

    this->vidas = _vidas;

    this->nave.inicializar(this->vidas, this->x_principal, this->y_principal);

    if(_cant_enemigos < 0){
        _cant_enemigos = 1;
    }
    else if(_cant_enemigos > 6) {
        _cant_enemigos = 6;

    }
    this->cant_enemigos = _cant_enemigos;

    this->_naves = new Nave_Enemiga* [this->cant_enemigos];

    for(int i = 0; i < this->cant_enemigos; i++){
        _naves[i] = new Nave_Enemiga(_vidas, _x_enemiga, _y_enemiga);

        _x_enemiga+= 25;
        _y_enemiga+= 5;
    }

    return;
}

void Juego_Naves::re_iniciar_juego(void){
    //PlaySound((LPCSTR)musica, NULL, SND_FILENAME | SND_ASYNC);

    Naves::kills = 0;

    int x = this->x_enemiga, y = this->y_enemiga;

    this->nave.inicializar(this->vidas, this->x_principal, this->y_principal);

    for(int i = 0; i < this->cant_enemigos; i++){
        _naves[i]->inicializar(this->vidas, x, y);

        x+= 25;
        y+=5;
    }

    return;
}

void Juego_Naves::jugar(void){
    string eleccion;
    do{
        while(true){
            nave.andando();
            nave.disparando();
            for(int i = 0; i < this->cant_enemigos; i++){
                if(nave.revisar_estado_nave(_naves[i]) <= 0){
                    goto fin_juego;
                }
            }
            for(int i = 0; i < this->cant_enemigos; i++){
                _naves[i]->andando();
                _naves[i]->disparando();
                _naves[i]->revisar_estado_nave(&nave);
            }
        }

        fin_juego:

        gotoxy(43, 1);cout << "FIN DEL JUEGO.";
        gotoxy(38, 3);cout << "Tus kills son de : " << Naves::kills;
        gotoxy(38, 5);cout << "Volver a Jugar? [si/no]";
        gotoxy(49, 6);cin >> eleccion;

        system("cls");

        if(eleccion == "si" || eleccion == "Si" || eleccion == "SI"){
            this->re_iniciar_juego();
        }

    }while(eleccion == "si" || eleccion == "Si" || eleccion == "SI");

    return;
}
