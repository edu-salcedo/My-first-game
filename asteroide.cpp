#include "asteroide.h"


Asteroide::Asteroide(int _x,int _y)
{
    x=_x;
    y=_y;
    ima_ast=load_bitmap("imagen/ares2.bmp",NULL);

}

void Asteroide::draw(BITMAP*buffer)
{
    draw_sprite(buffer,ima_ast,x,y);
}

void Asteroide::update(BITMAP*buffer)
{
    if (alarma.timer(5))
    {
        y++;

        if (y>SCREEN_H)
            y=0;
    }
    draw(buffer);
}
