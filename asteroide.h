#pragma once
#include <allegro.h>
#include"actor.h"
#include "alarma.h"


class Asteroide:public Actor
{
protected:
    BITMAP* ima_ast;
    Alarma alarma;
public:
    Asteroide(int, int);
    void draw(BITMAP*);
    void update(BITMAP*);

};
