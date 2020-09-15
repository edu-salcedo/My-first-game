#pragma once
#include<allegro.h>
#include "actor.h"

class Nave:public Actor
{
protected:
    float tam_vida;
    BITMAP* ima_nave;
    BITMAP*ima_vida;
    BITMAP*explo;
public:
     Nave();
     ~Nave();
    void draw(BITMAP*);
    void update();
    void destroy();


};
