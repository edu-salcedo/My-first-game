
#include "bala.h"

Bala ::Bala(int _x,int _y,int _tipo)
{
    this -> x = _x;
    this -> y = _y;
    this ->sprite=load_bitmap("imagen/bala.bmp",NULL);
  //  this->sprite= load_bitmap("imagen/rayo.bmp",NULL);

    this->tipo =_tipo;

}


void Bala::mov(BITMAP*buffer)
{
    switch(tipo)
    {
    case 1:

        if(y>0)
        {
            y--;
        }
        break;
    case 2:
          // int t=rand()%1000;
        if (y<SCREEN_H && tiempo.timer(5))  ///condicion para que la bala se mueva solo si "Y" es menor al tamaño de pantalla y el (rand) es mayor a 900
        {
            y++;

        }
        break;
    }
    draw_sprite(buffer,sprite,x,y);  ///dibuja la bala sobre el fondo
}


