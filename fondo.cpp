
#include "fondo.h"


Fondo::Fondo()
{
    ima_fondo=load_bitmap("imagen/fondo.bmp",NULL);
    x=0;
    y=0;
}


void Fondo::draw(BITMAP*lienzo)
{
        draw_sprite(lienzo,ima_fondo,x,ima_fondo->h*-1 + y);
		draw_sprite(lienzo,ima_fondo,x,ima_fondo->h*-2 + y);
		draw_sprite(lienzo,ima_fondo,x,y);
		draw_sprite(lienzo,ima_fondo,x,ima_fondo->h + y);
		draw_sprite(lienzo,ima_fondo,x,ima_fondo->h*2 + y);
		y+=0.1;

		if(y <= ima_fondo->h*-1 or y >= ima_fondo->h)
		{	y = 0;	}

}

void Fondo::destroy()
{
    destroy_bitmap(ima_fondo);
}
