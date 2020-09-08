#pragma once
#include <allegro.h>
#include"actor.h"
#include "alarma.h"

class Alarma;
class Enemigo:public Actor
{
protected:
    //int vida;
    float tam_vida;
    BITMAP* ima_enemy;
    BITMAP* ima_vida;
    Alarma alarm;
    int dx;
    int dy;
    int cont;
public:
    Enemigo(int ,int );
    ~Enemigo();
    void draw(BITMAP*);
    void create();
    void update(BITMAP*);



};




