#include "enemigo.h"
#include<math.h>
#include <time.h>

Enemigo::Enemigo (int _x,int _y)
{
    x=_x;
    y=_y;
    ima_enemy=load_bitmap("imagen/bos.bmp",NULL);
    ima_vida=load_bitmap("imagen/b_vida.bmp",NULL);
    vida=100;
    dx=2;
    dy=2;
    cont =1;
}

void Enemigo::draw(BITMAP*buffer)
{

    draw_sprite(buffer,ima_enemy,x,y);
    tam_vida = (50.0/100.0) * vida;
    stretch_sprite(buffer,ima_vida,x,y+ima_enemy->h/2,tam_vida,5);

}

void Enemigo::update(BITMAP*buffer)
{
    if(alarm.timer(10))
    {
        x+=dx;
        y+=dy;

        if(y >=400)  ///esta condicion determina hasta donde hace el movimiento de caida el enemigo
        {
            cont = -1;
        }

        if(cont == -1)
        {
           dy= pow((x-(x - SCREEN_H/4))/100,2) * cont;  ///si toca los extremos X de la pantalla rebota

        }
        else if (rand()%500>490)
        {
           dy= pow(x/100,2);          ///hace que la nave haga un movimiento de caida
        }


         if (x<SCREEN_W-40)dx= -dx;
         if (x>0)dx=-dx;
         if (y<200)cont =1;   /// para que no salga de la pantalla hacia arriba si se pone menor valor se sale de la pantalla

    }

    draw(buffer);
}


Enemigo::~Enemigo()
{
    destroy_bitmap(ima_enemy);
}
