#pragma once
#include <list>
#include <allegro.h>
using namespace std;
#include "fondo.h"
#include "menu.h"
#include "alarma.h"
#include "enemigo.h"
#include "bala.h"
#include "asteroide.h"
class Game
{

private:
    BITMAP* buffer;
    bool gameover;
    int nivel ;
    int numenemigo;
    Menu menu;
    Fondo *fondo;
    list<Enemigo*>enemy;
    list<Bala*>balas;
    list<Bala*>bala_enemy;
    list<Bala *>::iterator itbala;         ///creamos in iterador para las balas
    list<Enemigo*>::iterator itenemy;     ///creamos in iterador para las enemigos
    list<Bala *>::iterator itbalaEne;
    list<Asteroide*>aste;
    list<Asteroide*>::iterator itaste;
public:
    Game();
    void update();
    void draw();
    void dispose();
    void main();
    void start();
    void init();
    void shutdown();
    bool collition(int);
    void level();

};
