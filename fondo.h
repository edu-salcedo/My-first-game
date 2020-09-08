#include <allegro.h>
#pragma once

class Fondo
{
private :
    float y;
    float x;
    BITMAP* ima_fondo;
public:
    Fondo();
    void draw(BITMAP*);
    void destroy();

};
