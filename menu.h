
#include <allegro.h>
#pragma once

class Menu
{
private:
    BITMAP* fondo;
    BITMAP* fondo1;
    BITMAP* fondo2;
    BITMAP* fondo3;
    BITMAP*cursor;
    BITMAP* over;
    BITMAP* fnivel;
    BITMAP* imag_vida;
    BITMAP*explo2;

public:

    int draw(BITMAP*);
    void inicio();
    void gameover(BITMAP*);
    void nivel(BITMAP*);
    void vidas(BITMAP*,int);

};
